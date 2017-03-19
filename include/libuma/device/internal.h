#ifndef UMA_DEVICE_INTERNAL_H
#define UMA_DEVICE_INTERNAL_H

#include <libusb-1.0/libusb.h>
#include <libuma/device/type.h>

#ifdef __cplusplus
extern "C" {
#endif

struct mooltipass_device {
	libusb_device *usb_device;
	libusb_device_handle *usb_handle;
};

#ifdef __cplusplus
}
#endif

#endif //UMA_DEVICE_INTERNAL_H
