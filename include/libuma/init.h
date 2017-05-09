#ifndef UMA_INIT_H
#define UMA_INIT_H

#include <libuma/retcode.h>

#ifdef __cplusplus
extern "C" {
#endif

uma_ret_code uma_init();
void uma_shutdown();

#ifdef __cplusplus
}
#endif

#endif //UMA_INIT_H
