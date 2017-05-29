#include <libuma/device/handler.h>
#include <libuma/device/internal.h>
#include <libuma/usb/device_info.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

uma_ret_code uma_device_list(uma_Mooltipass_list *mooltipass_list) {
	libusb_device **devices;
	ssize_t device_list_result;
	size_t device_count;

	if(mooltipass_list == NULL) {
		return UMA_ERROR_BAD_ARGS;
	}

	// Get list of all usb devices
	device_list_result = libusb_get_device_list(NULL, &devices);

	if(device_list_result < 0) {
		const char* err_message = libusb_strerror((enum libusb_error)device_list_result);
		printf("Cannot get usb device list: %s", err_message);

		return UMA_ERROR_DEVICE_USB_LIST;
	}
	device_count = device_list_result;
	printf("%zu USB devices found\n", device_count);

	// Find any potential mooltipass devices among the usb devices
	for(size_t i = 0; i < device_count; i++) {
		int result = 0;
		libusb_device *device = devices[i];
		struct libusb_device_descriptor device_info;

		// Check device descriptor
		result = libusb_get_device_descriptor(device, &device_info);

		if(result != LIBUSB_SUCCESS) {
			const char* err_message = libusb_strerror((enum libusb_error)device_list_result);
			printf("Cannot get usb device information: %s\n", err_message);
			continue;
		}

		//printf("Checking device on bus %.3d:%.3d (%d ports) ID %.4x::%.4x\n", libusb_get_bus_number(device), libusb_get_device_address(device), libusb_get_port_number(device), device_info.idVendor, device_info.idProduct);
		if((device_info.idVendor != MOOLTIPASS_VENDOR_ID) || (device_info.idProduct != MOOLTIPASS_PRODUCT_ID)) {
			libusb_unref_device(device);
			continue;
		}

		// A potential mooltipass device has been found. List it
		mooltipass_list->count++;
		mooltipass_list->devices = realloc(mooltipass_list->devices, mooltipass_list->count * sizeof(uma_Mooltipass));
		mooltipass_list->devices[mooltipass_list->count - 1] = malloc(sizeof(struct mooltipass_device));
		mooltipass_list->devices[mooltipass_list->count - 1]->usb_device = device;
	}
	libusb_free_device_list(devices, 0);

	return UMA_SUCCESS;
}

void uma_device_list_release(uma_Mooltipass_list *mooltipass_list) {

	for(size_t idx = 0; idx < mooltipass_list->count; idx++) {
		libusb_unref_device(mooltipass_list->devices[idx]->usb_device);
		free(mooltipass_list->devices[idx]);
	}
	free(mooltipass_list->devices);
}

uma_ret_code uma_device_open(uma_Mooltipass mooltipass) {
	int result;

	assert(mooltipass != NULL);

	result = libusb_open(mooltipass->usb_device, &mooltipass->usb_handle);

	if(result != LIBUSB_SUCCESS) {
		const char* err_message = libusb_strerror(result);
		printf("Cannot open usb device: %s\n", err_message);

		return UMA_ERROR_DEVICE_OPEN;
	}
	printf("Mooltipass opened\n");
	libusb_set_auto_detach_kernel_driver(mooltipass->usb_handle, 1);

	result = libusb_claim_interface(mooltipass->usb_handle, 0);

	if(result != LIBUSB_SUCCESS) {
		const char* err_message = libusb_strerror(result);
		printf("Cannot open usb device: %s\n", err_message);

		return UMA_ERROR_DEVICE_CLAIM;
	}
	return UMA_SUCCESS;
}

void uma_device_close(uma_Mooltipass mooltipass) {

	libusb_close(mooltipass->usb_handle);

	// Mooltipass element is freed as this pointer is opaque
	free(mooltipass);
}

uma_ret_code uma_device_open_first(uma_Mooltipass *mooltipass) {
	enum uma_ret_code result = 0;
	uma_Mooltipass_list mooltipass_devices = {0};

	result = uma_device_list(&mooltipass_devices);

	if(result != UMA_SUCCESS) {
		return result;
	}

	if(mooltipass_devices.count == 0) {
		return UMA_ERROR_DEVICE_NOT_FOUND;
	}
	result = uma_device_open(mooltipass_devices.devices[0]);

	if(result == UMA_SUCCESS) {
		(*mooltipass) = malloc(sizeof(struct mooltipass_device));
		(*mooltipass)->usb_device = mooltipass_devices.devices[0]->usb_device;
		(*mooltipass)->usb_handle = NULL;
	}
	uma_device_list_release(&mooltipass_devices);

	return result;
}

uma_ret_code uma_device_open_idx(uma_Mooltipass *mooltipass, size_t index) {
	enum uma_ret_code result = 0;
	uma_Mooltipass_list mooltipass_devices = {0};

	result = uma_device_list(&mooltipass_devices);

	if(result != UMA_SUCCESS) {
		return result;
	}

	if(mooltipass_devices.count == 0) {
		uma_device_list_release(&mooltipass_devices);

		return UMA_ERROR_DEVICE_NOT_FOUND;
	}

	if(mooltipass_devices.count <= index) {
		uma_device_list_release(&mooltipass_devices);

		return UMA_ERROR_DEVICE_NOT_FOUND;
	}
	result = uma_device_open(mooltipass_devices.devices[index]);

	if(result == UMA_SUCCESS) {
		(*mooltipass) = malloc(sizeof(struct mooltipass_device));
		memcpy((*mooltipass), mooltipass_devices.devices[index], sizeof(struct mooltipass_device));
	}
	uma_device_list_release(&mooltipass_devices);

	return result;
}

void uma_device_info_print(uma_Mooltipass mooltipass) {
	struct libusb_device_descriptor desc;
	struct libusb_config_descriptor *config;

	int result = 0;

	result = libusb_get_device_descriptor(mooltipass->usb_device, &desc);

	if(result != LIBUSB_SUCCESS) {
		printf("Cannot get device descriptor\n");

		return;
	}
	printf("Number of possible configurations: %d\n", desc.bNumConfigurations);
	printf("Device Class: %d\n", (int)desc.bDeviceClass);
	printf("VendorID:  0x%.4x\n", desc.idVendor);
	printf("ProductID: 0x%.4x\n", desc.idProduct);

	libusb_get_config_descriptor(mooltipass->usb_device, 0, &config);

	printf("Interfaces: (%d):\n", (int)config->bNumInterfaces);

	for(int i = 0; i < (int)config->bNumInterfaces; i++) {
		const struct libusb_interface *interface;
		interface = &config->interface[i];
		printf("\tNumber of alternate settings: %d\n", interface->num_altsetting);

		if(interface->num_altsetting > 0) {
			for(size_t j = 0; j < (size_t)interface->num_altsetting; j++) {
				const struct libusb_interface_descriptor *interface_description;
				interface_description = &interface->altsetting[j];
				printf("\t\tInterface Number: %d\n", interface_description->bInterfaceNumber);
				printf("\t\tNumber of endpoints: %d\n", (int)interface_description->bNumEndpoints);

				for(int k = 0; k < (int)interface_description->bNumEndpoints; k++) {
					const struct libusb_endpoint_descriptor *endpoint_description;
					endpoint_description = &interface_description->endpoint[k];
					printf("\t\t\tDescriptor Type: %d\n",endpoint_description->bDescriptorType);
					printf("\t\t\tEP Address: %d\n", endpoint_description->bEndpointAddress);
				}
			}
		}
	}
	libusb_free_config_descriptor(config);
}
