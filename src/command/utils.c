#include <libuma/command/type.h>
#include <libuma/command/utils.h>
#include <libuma/command/original.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

int moopass_command_name_get(char const ** name, uint8_t command_id) {

	for(size_t i = 0; i < uma_command_original_size; i++) {
		if(uma_command_original[i].id == command_id) {
			(*name) = uma_command_original[i].name;

			return 0;
		}
	}
	return 1;
}

int moopass_command_id_get_from_name(char const * const name, uint8_t *command_id) {

	assert(command_id != NULL);

	for(size_t i = 0; i < uma_command_original_size; i++) {
		if(strcmp(uma_command_original[i].name, name) == 0) {
			if(command_id != NULL) {
				(*command_id) = uma_command_original[i].id;
			}
			return 0;
		}
	}
	return 1;
}

int moopass_command_get_from_id(uint8_t command_id, uma_command_info **command_info) {

	for(size_t i = 0; i < uma_command_original_size; i++) {
		if(uma_command_original[i].id == command_id) {
			(*command_info) = &(uma_command_original[i]);

			return 0;
		}
	}
	return 1;
}

int moopass_command_get_from_name(char const * const name, uma_command_info **command_info) {

	for(size_t i = 0; i < uma_command_original_size; i++) {
		if(strcmp(uma_command_original[i].name, name) == 0) {
			(*command_info) = &(uma_command_original[i]);

			return 0;
		}
	}
	return 1;
}

void command_list_print(FILE *output, size_t level, bool request_response_print, char const * prefix) {
	uma_command_info *command_info;
	const char indent[] = "\t";

	for(size_t i = 0; i < uma_command_original_size; i++) {
		command_info = &(uma_command_original[i]);

		for(size_t level_count = 0; level_count < level; level_count++) {
			fprintf(output, "%s", indent);
		}
		fprintf(output, "%s%s: %s\n", prefix, command_info->name, command_info->description);

		if(request_response_print) {
			for(size_t level_count = 0; level_count < level + 1; level_count++) {
				fprintf(output, "%s", indent);
			}
			fprintf(output, "Request: %s\n", command_info->request);

			for(size_t level_count = 0; level_count < level + 1; level_count++) {
				fprintf(output, "%s", indent);
			}
			fprintf(output, "Response: %s\n", command_info->response);
		}
	}
}
