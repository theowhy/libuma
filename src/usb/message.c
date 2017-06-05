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

void uma_usb_message_hexadump(uma_usb_message *message, unsigned int page_size) {
	char tmp[page_size + 1];
	size_t i;

	tmp[page_size + 1] = 0;
	printf("0x%x.\nData (%d):\n", message->message_id, message->data_size);

	for(i = 0; i < message->data_size; i++) {
		printf("%.2x", message->data[i]);

		if(isprint(message->data[i])) {
			tmp[i % page_size] = message->data[i];
		} else {
			tmp[i % page_size] = '.';
		}
		printf(" ");

		if(i % 10 == 9) {
			printf("| %s\n", tmp);
		}
	}

	// Write the end of the line
	while(i % page_size != page_size + 1) {
		printf(".. ");
		tmp[i % page_size] = '.';
		i++;
	}

	if(i % 10 == 9) {
		printf("| %s\n", tmp);
	}
}
