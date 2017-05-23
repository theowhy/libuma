#include <libuma/command/type.h>

#ifndef UMA_COMMAND_UTILS_H
#define UMA_COMMAND_UTILS_H

char* moopass_command_name_get_from_id(uma_command_info* commands, size_t command_count, uint8_t raw_command_id);
int moopass_command_id_get_from_name();

#endif //UMA_COMMAND_UTILS_H
