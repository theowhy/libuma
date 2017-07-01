
#ifndef UMA_RET_CODE_H
#define UMA_RET_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

enum uma_ret_code {
	// Generic error
	UMA_SUCCESS = 0,
	UMA_ERROR_BAD_ARGS,

	// Generic found/not found
	UMA_FOUND = 1,
	UMA_NOT_FOUND = 0,

	// USB errors
	UMA_ERROR_USB_INIT = 0x00010000,

	// handler errors
	UMA_ERROR_DEVICE_INVALID_HANDLE = 0x00020000,
	UMA_ERROR_DEVICE_NOT_FOUND,
	UMA_ERROR_DEVICE_OPEN,
	UMA_ERROR_DEVICE_CLAIM,
	UMA_ERROR_DEVICE_USB_LIST,
};

typedef enum uma_ret_code uma_ret_code;

const char * error_info_get(uma_ret_code return_code, const char ** const help);

#ifdef __cplusplus
}
#endif

#endif //UMA_RET_CODE_H
