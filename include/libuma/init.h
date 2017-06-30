#ifndef UMA_INIT_H
#define UMA_INIT_H

#include <libuma/retcode.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * Initialize library. A call to this function is required before using any other library's function.
 * After using the library, a clean up must be made using \ref uma_shutdown
 *
 * \return UMA_SUCCESS on success or UMA_ERROR_USB_INIT if the USB sub system cannot be initialized
 */
uma_ret_code uma_init();

/*!
 * \brief Cleans everything up.
 *
 * After using the library's functions, calling this function will deinitialized USB sub system and clean library's internals<.
 *
 */
void uma_shutdown();

#ifdef __cplusplus
}
#endif

#endif //UMA_INIT_H
