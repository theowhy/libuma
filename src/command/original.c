#include <libuma/command/original.h>

uma_command_info uma_command_original[] = {
	{0xA1, "PING", "Send a 4 bytes payload to mooltipass and it will echo it back"},
	{0xA2, "GET_VERSION", "Retrieve mooltipass firmware version"},
	{0xA3, "CONTEXT", ""},
	{0xA4, "GET_LOGIN", ""},
	{0xA5, "GET_PASSWORD", ""},
	{0xA6, "SET_LOGIN", ""},
	{0xA7, "SET_PASSWORD", ""},
	{0xA8, "CHECK_PASSWORD", ""},
	{0xA9, "ADD_CONTEXT", ""},
	{0xAA, "SET_BOOTLOADER_PWD", ""},
	{0xAB, "JUMP_TO_BOOTLOADER", ""},
	{0xAC, "GET_RANDOM_NUMBER", ""},
	{0xAD, "START_MEMORYMGMT", ""},
	{0xAE, "IMPORT_MEDIA_START", ""},
	{0xAF, "IMPORT_MEDIA", ""},
	{0xB0, "IMPORT_MEDIA_END", ""},
	{0xB1, "SET_MOOLTIPASS_PARM", ""},
	{0xB2, "GET_MOOLTIPASS_PARM", ""},
	{0xB3, "RESET_CARD", ""},
	{0xB4, "READ_CARD_CREDS", ""},
	{0xB5, "RESERVED", ""},
	{0xB6, "SET_CARD_LOGIN", ""},
	{0xB7, "SET_CARD_PASS", ""},
	{0xB8, "ADD_UNKNOWN_CARD", ""},
	{0xB9, "STATUS", ""},
	{0xBA, "FUNCTIONAL_TEST_RES", ""},
	{0xBB, "SET_DATE", ""},
	{0xBC, "SET_UID", ""},
	{0xBD, "GET_UID", ""},
	{0xBE, "SET_DATA_SERVICE", ""},
	{0xBF, "ADD_DATA_SERVICE", ""},
	{0xC0, "WRITE_32B_IN_DN", ""},
	{0xC1, "READ_32B_IN_DN", ""},
	{0xC2, "GET_CUR_CARD_CPZ", ""},
	{0xC3, "CANCEL_REQUEST", ""},
	{0xC4, "PLEASE_RETRY", ""},
	{0xC5, "READ_FLASH_NODE", ""},
	{0xC6, "WRITE_FLASH_NODE", ""},
	{0xC7, "GET_FAVORITE", ""},
	{0xC8, "SET_FAVORITE", ""},
	{0xC9, "GET_STARTING_PARENT", ""},
	{0xCA, "SET_STARTING_PARENT", ""},
	{0xCB, "GET_CTRVALUE", ""},
	{0xCC, "SET_CTRVALUE", ""},
	{0xCD, "ADD_CARD_CPZ_CTR", ""},
	{0xCE, "GET_CARD_CPZ_CTR", ""},
	{0xCF, "CARD_CPZ_CTR_PACKET", ""},
	{0xD0, "GET_FREE_SLOTS_ADDR", ""},
	{0xD1, "GET_DN_START_PARENT", ""},
	{0xD2, "SET_DN_START_PARENT", ""},
	{0xD3, "END_MEMORYMGMT", ""},
	{0xD4, "SET_USER_CHANGE_NB", ""},
	{0xD5, "GET_DESCRIPTION", ""},
	{0xD6, "GET_USER_CHANGE_NB", ""},
	{0xD7, "GET_FREE_NB_USR_SLT", ""},
	{0xD8, "SET_DESCRIPTION", ""},
	{0xD9, "LOCK_DEVICE", ""},
	{0xDA, "GET_MINI_SERIAL", ""},
	{0xDB, "UNLOCK_WITH_PIN", ""},
};

const size_t uma_command_original_size = sizeof(uma_command_original) / sizeof(uma_command_info);
