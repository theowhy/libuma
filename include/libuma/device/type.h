#ifndef UMA_DEVICE_TYPE_H
#define UMA_DEVICE_TYPE_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

enum uma_firmware_familly {
	UMA_FIRMWARE_UNKNOWN = 0,
	UMA_FIRMWARE_STANDARD = 1
};

enum uma_device_types {
	UMA_MOOLTIPASS_UNKNOWN = 0,
	UMA_MOOLTIPASS_STANDARD = 1,
	UMA_MOOLTIPASS_MINI
};

typedef struct mooltipass_device* uma_Mooltipass;

typedef struct mooltipass_list {
	uma_Mooltipass *devices;
	size_t count;
} uma_Mooltipass_list;

#ifdef __cplusplus
}
#endif

#endif //UMA_DEVICE_TYPE_H
