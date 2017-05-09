#include <libuma/init.h>
#include <libusb-1.0/libusb.h>

uma_ret_code uma_init() {
	if(libusb_init(NULL) != LIBUSB_SUCCESS) {
		return UMA_SUCCESS;
	}
	return UMA_SUCCESS;
}

void uma_shutdown() {
	libusb_exit(NULL);
}
