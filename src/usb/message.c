#include "libuma/usb/message.h"
#include <stdio.h>
#include <ctype.h>

void uma_usb_message_dump(uma_usb_message *message) {

	if(message != NULL) {
		printf("0x%x ", message->message_id);
		printf("[%u bytes] => ", message->data_size);

		for(size_t i = 0; i < message->data_size; i++) {
			printf("0x%x", message->data[i]);
		}
		printf(" (");

		for(size_t i = 0; i < message->data_size; i++) {
			if(isprint(message->data[i]) != 0) {
				printf("%c", message->data[i]);
			} else {
				printf(".");
			}
		}
		printf(")\n");
	}
}
