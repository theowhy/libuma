#ifndef UMA_DEVICE_HANDLER_H
#define UMA_DEVICE_HANDLER_H

#include <libuma/retcode.h>
#include <libuma/device/type.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

uma_ret_code uma_device_list(uma_Mooltipass_list *mooltipass_list);
void uma_device_list_release(uma_Mooltipass_list *mooltipass_list);
uma_ret_code uma_device_open(uma_Mooltipass mooltipass);
void uma_device_close(uma_Mooltipass mooltipass);
uma_ret_code uma_device_open_first(uma_Mooltipass *mooltipass);
uma_ret_code uma_device_open_idx(uma_Mooltipass *mooltipass, size_t index);
void uma_device_info_print(uma_Mooltipass mooltipass);

#ifdef __cplusplus
}
#endif
#endif //UMA_DEVICE_HANDLER_H
