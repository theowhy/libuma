#include <libuma/command/type.h>
#include <libuma/command/utils.h>
#include <stdint.h>

char* moopass_command_name_get_from_id(uma_command_info* commands, size_t command_count, uint8_t raw_command_id) {

	for(size_t idx = 0; idx < command_count; idx++) {
		if(commands[idx].id == raw_command_id) {
			return (char*)commands[idx].name;
		}
	}
	return NULL;
}

int moopass_command_id_get_from_name() {
	return 0;

}
