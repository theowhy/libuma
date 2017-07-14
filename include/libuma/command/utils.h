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
 * \param[out] name name of the command
 * \param[in] command_id The ID of the command to look for
 *
 * \return  UMA_FOUND if the command is found or UMA_NOT_FOUND otherwhise.
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

/*!
 * \brief Pretty print a list of command
 *
 * \param[out] output File stream to print into
 * \param[in] level Indentation level
 * \param[in] request_response_print Boolean that indicates if the requests and responses should be printed with the command
 * \param[in] prefix String to use in order to prefix each command
 */
void command_list_print(FILE *output, size_t level, bool request_response_print, char const *prefix);

#ifdef __cplusplus
}
#endif

#endif //UMA_COMMAND_UTILS_H
