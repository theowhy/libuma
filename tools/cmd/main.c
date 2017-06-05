#include <stdio.h>
#include <libuma/init.h>
#include <libuma/usb/sync.h>
#include <libuma/device/handler.h>
#include <argp.h>
#include <stdbool.h>
#include <string.h>

enum mode {
	SEND = 1,
	READ,
};

typedef struct configuration {
	bool verbose;
	size_t device_index;
	enum mode mode;
	uint8_t command_id;
	const char* data;
} Configuration;

static int parse_callback(int key, char *arg, struct argp_state *state) {
	Configuration *configuration = state->input;
	char *valid_num = NULL;

	switch(key) {
		case 's':
			configuration->mode = SEND;
			configuration->command_id = strtol(arg, &valid_num, 16);

			if(valid_num[0] != '\0') {
				printf("%s\n", valid_num);
				exit(1);
			}
			valid_num = NULL;
			break;
		case 'r':
			configuration->mode = READ;
			break;

		// Common option handling
		case 'm':
			configuration->device_index = strtol(arg, &valid_num, 16);

			if(valid_num[0] != '\0') {
				printf("%s\n", valid_num);
				exit(1);
			}
			valid_num = NULL;
			break;
		case 'h':
			argp_usage(state);
			exit(0);
			break;
		case 'd':
			configuration->data = arg;
			break;
		case 'v':
			configuration->verbose = true;
			break;
		default:

			return ARGP_ERR_UNKNOWN;
			break;
	}

	return 0;
}

/* Program documentation. */
static char program_description[] =
	"Simple CLI to exchange messages with mooltipass device";

static char args_documentation[] = "";

static struct argp_option options[] = {
	{"send", 's', "COMMAND_ID", 0, "Send message to mooltipass"},
	{"read", 'r', NULL, 0, "Read message from mooltipass"},
	{"data", 'd', "VALUE", 0, "Data to use"},
	{"mooltipass", 'm', "ID", 0, "Index of the mooltipass to use (default is the first device which index is 0)"},
	{"verbose", 'v', NULL, 0,  "Produce verbose output" },
	{NULL, 0, 0, 0, NULL}
};

int main(int argc, char **argv) {
	uma_ret_code result;
	Configuration configuration = {0};
	struct argp argp = {options, parse_callback, args_documentation, program_description};
	uma_Mooltipass mooltipass;

	if(argp_parse(&argp, argc, argv, 0, NULL, &configuration) != 0) {
		return 1;
	}
	uma_init();
	result = uma_device_open_idx(&mooltipass, configuration.device_index);

	if(result != UMA_SUCCESS) {
		printf("Cannot open device\n");

		uma_shutdown();

		return 1;
	}
	switch(configuration.mode) {
		case SEND:
		{
			uma_usb_message request;
			memset(&request, 0, sizeof(uma_usb_message));
			request.message_id = configuration.command_id;

			if(configuration.data != NULL) {
				request.data_size = strlen(configuration.data);
				memcpy(request.data, configuration.data, request.data_size);
				request.data[request.data_size] = '\0';
			}
			uma_usb_message_dump(&request);
			printf("send request\n");
			uma_usb_sync_send(mooltipass, &request);
			break;
		}
		case READ:
		{
			uma_usb_message response = {0};
			uma_usb_sync_read(mooltipass, &response);

			uma_usb_message_dump(&response);
		}
		break;
		default:
			break;
	}

	uma_device_close(mooltipass);
	uma_shutdown();

	return 0;
}
