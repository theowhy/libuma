#include <libuma/usb/message.h>
#include <libuma/device/handler.h>

// Synchronous low level library
uma_ret_code uma_usb_sync_send(uma_Mooltipass mooltipass, uma_usb_message* message);
uma_ret_code uma_usb_sync_read(uma_Mooltipass mooltipass, uma_usb_message *message);
