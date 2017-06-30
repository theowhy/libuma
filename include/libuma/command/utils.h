#include <libuma/command/type.h>

#ifndef UMA_COMMAND_UTILS_H
#define UMA_COMMAND_UTILS_H

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
char* moopass_command_name_get_from_id(uma_command_info* commands, size_t command_count, uint8_t raw_command_id);

/*!
 * \brief Get command ID from the given string name
 *
 * \return Nothing. This functions is not yet implemented
 */
int moopass_command_id_get_from_name();

#endif //UMA_COMMAND_UTILS_H
