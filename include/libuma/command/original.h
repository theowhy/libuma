#include <stddef.h>
#include <stdint.h>
#include <libuma/command/type.h>

#ifndef UMA_COMMAND_ORIGINAL_H
#define UMA_COMMAND_ORIGINAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Command IDs enumeration
 *
 * Enumeration that can be used when sending commands.
 * \see uma_command_original for a description of the commands
 */
enum UMA_COMMAND_ORIGINAL {
	PING = 0xA1,
	GET_VERSION = 0xA2,
	CONTEXT = 0xA3,
	GET_LOGIN = 0xA4,
	GET_PASSWORD = 0xA5,
	SET_LOGIN = 0xA6,
	SET_PASSWORD = 0xA7,
	CHECK_PASSWORD = 0xA8,
	ADD_CONTEXT = 0xA9,
	SET_BOOTLOADER_PWD = 0xAA,
	JUMP_TO_BOOTLOADER = 0xAB,
	GET_RANDOM_NUMBER = 0xAC,
	START_MEMORYMGMT = 0xAD,
	IMPORT_MEDIA_START = 0xAE,
	IMPORT_MEDIA = 0xAF,
	IMPORT_MEDIA_END = 0xB0,
	SET_MOOLTIPASS_PARM = 0xB1,
	GET_MOOLTIPASS_PARM = 0xB2,
	RESET_CARD = 0xB3,
	READ_CARD_CREDS = 0xB4,
	RESERVED = 0xB5,
	SET_CARD_LOGIN = 0xB6,
	SET_CARD_PASS = 0xB7,
	ADD_UNKNOWN_CARD = 0xB8,
	STATUS = 0xB9,
	FUNCTIONAL_TEST_RES = 0xBA,
	SET_DATE = 0xBB,
	SET_UID = 0xBC,
	GET_UID = 0xBD,
	SET_DATA_SERVICE = 0xBE,
	ADD_DATA_SERVICE = 0xBF,
	WRITE_32B_IN_DN = 0xC0,
	READ_32B_IN_DN = 0xC1,
	GET_CUR_CARD_CPZ = 0xC2,
	CANCEL_REQUEST = 0xC3,
	PLEASE_RETRY = 0xC4,
	READ_FLASH_NODE = 0xC5,
	WRITE_FLASH_NODE = 0xC6,
	GET_FAVORITE = 0xC7,
	SET_FAVORITE = 0xC8,
	GET_STARTING_PARENT = 0xC9,
	SET_STARTING_PARENT = 0xCA,
	GET_CTRVALUE = 0xCB,
	SET_CTRVALUE = 0xCC,
	ADD_CARD_CPZ_CTR = 0xCD,
	GET_CARD_CPZ_CTR = 0xCE,
	CARD_CPZ_CTR_PACKET = 0xCF,
	GET_FREE_SLOTS_ADDR = 0xD0,
	GET_DN_START_PARENT = 0xD1,
	SET_DN_START_PARENT = 0xD2,
	END_MEMORYMGMT = 0xD3,
	SET_USER_CHANGE_NB = 0xD4,
	GET_DESCRIPTION = 0xD5,
	GET_USER_CHANGE_NB = 0xD6,
	GET_FREE_NB_USR_SLT = 0xD7,
	SET_DESCRIPTION = 0xD8,
	LOCK_DEVICE = 0xD9,
	GET_MINI_SERIAL = 0xDA,
	UNLOCK_WITH_PIN = 0xDB,
};

/*!
 * \brief Supported commands array
 *
 * This array contains the descriptions for every commands supported by the mooltipass device original firmware
 */
extern uma_command_info uma_command_original[];

/*!
 * \brief Number of commands in original mooltipass firmware
 *
 * This count is also the exact number of entries in the \ref uma_command_original array
 */
extern const size_t uma_command_original_size;

#ifdef __cplusplus
}
#endif

#endif //UMA_COMMAND_ORIGINAL_H
