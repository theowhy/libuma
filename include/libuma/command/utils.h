#ifndef UMA_COMMAND_UTILS_H
#define UMA_COMMAND_UTILS_H

#include <libuma/command/type.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Get command string name representation for the the given command_id
 *
 * In the given commands array of command_count elements, a command with raw_command_id is searched.
 *
 * \param commands Array containing the commands to look into
 * \param command_count The number of commands in the commands array
 * \param raw_command_id The ID of the command to look for
 *
 * \return  The name (see name field of \ref uma_command_info structure) if the command is found.\n
 * Otherwise, NULL is returned
 */
int moopass_command_name_get(char const ** name, uint8_t command_id);

/*!
 * \brief Get command ID from the given string name
 *
 * \return Nothing. This functions is not yet implemented
 */
int moopass_command_id_get_from_name(char const * const name, uint8_t *command_id);
int moopass_command_get_from_id(uint8_t command_id, uma_command_info **command_info);
int moopass_command_get_from_name(char const * const name, uma_command_info **command_info);
void command_list_print(FILE *output, size_t level, bool request_response_print, char const *prefix);

#ifdef __cplusplus
}
#endif

#endif //UMA_COMMAND_UTILS_H
