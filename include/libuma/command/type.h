#ifndef UMA_COMMAND_TYPE_H
#define UMA_COMMAND_TYPE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct uma_command_info {
	uint8_t id;
	const char *name;
	const char *description;
} uma_command_info;

#ifdef __cplusplus
}
#endif

#endif //UMA_COMMAND_TYPE_H
