// Synchronous library
#include <libuma/usb/sync.h>
#include <libuma/device/internal.h>
#include <libusb-1.0/libusb.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

uma_ret_code uma_usb_sync_send(uma_Mooltipass mooltipass, uma_usb_message* message) {
	int data_send = 0;
	int result;

	result = libusb_bulk_transfer(mooltipass->usb_handle, LIBUSB_ENDPOINT_OUT | 2, (unsigned char*)message, 2 + message->data_size, &data_send, 10000);

	if(result != LIBUSB_SUCCESS) {
		const char* err_message = libusb_strerror(result);
		printf("Cannot send data to device: %s\n", err_message);

		return 0;
	}
	return UMA_SUCCESS;
}

uma_ret_code uma_usb_sync_read(uma_Mooltipass mooltipass, uma_usb_message *message) {
	int data_read;
	int result;

	memset(message, 0, 64);
	result = libusb_bulk_transfer(mooltipass->usb_handle, LIBUSB_ENDPOINT_IN | 1, (unsigned char *)message, 64, &data_read, 10000);

	if(result != LIBUSB_SUCCESS) {
		const char* err_message = libusb_strerror(result);
		printf("Cannot send data to device: %s\n", err_message);

		return UMA_ERROR_DEVICE_INVALID_HANDLE;
	}
	return UMA_SUCCESS;
}
