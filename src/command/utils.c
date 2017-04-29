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
