#ifndef UMA_COMMAND_TYPE_H
#define UMA_COMMAND_TYPE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Description of a command
 */
typedef struct uma_command_info {
	uint8_t id; ///< ID of the command
	const char *name; ///< Human readable mapping of the command's ID
	const char *description; ///< Human readable description of the command
} uma_command_info;

#ifdef __cplusplus
}
#endif

#endif //UMA_COMMAND_TYPE_H
