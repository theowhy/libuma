#include <libuma/command/original.h>

uma_command_info uma_command_original[] = {
	{
		.id = 0xA0,
		.name = "DEBUG_MSG",
		.description = "Debug message sent by mooltipass",
		.request = "This command should not be sent by user",
		.response = "Contains a string with the message"
	},{
		.id = 0xA1,
		.name = "PING",
		.description = "Send a 4 bytes payload to mooltipass and it will echo it back",
		.request = "4 bytes payload",
		.response = "The same packet as the one received"
	},{
		.id = 0xA2,
		.name = "VERSION_GET",
		.description = "Retrieve mooltipass firmware version",
		.request = "Empty",
		.response = "The first byte contains the FLASH_CHIP define which specifies how much memory the Mooltipass has. The rest is a string identifying the version in the vX.X format. The Mooltipass Mini has '_mini' appended to the version string."
	},{
		.id = 0xA3,
		.name = "CONTEXT_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA4,
		.name = "LOGIN_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA5,
		.name = "PASSWORD_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA6,
		.name = "LOGIN_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA7,
		.name = "PASSWORD_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA8,
		.name = "CHECK_PASSWORD",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xA9,
		.name = "CONTEXT_ADD",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAA,
		.name = "BOOTLOADER_PWD_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAB,
		.name = "JUMP_TO_BOOTLOADER",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAC,
		.name = "RANDOM_NUMBER_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAD,
		.name = "MEMORYMGMT_ENTER",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAE,
		.name = "IMPORT_MEDIA_START",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xAF,
		.name = "IMPORT_MEDIA",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB0,
		.name = "IMPORT_MEDIA_END",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB1,
		.name = "MOOLTIPASS_PARM_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB2,
		.name = "MOOLTIPASS_PARM_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB3,
		.name = "CARD_RESET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB4,
		.name = "READ_CARD_CREDS",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB5,
		.name = "RESERVED",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB6,
		.name = "CARD_LOGIN_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB7,
		.name = "CARD_PASS_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB8,
		.name = "UNKNOWN_CARD_ADD",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xB9,
		.name = "STATUS_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBA,
		.name = "FUNCTIONAL_TEST_RES",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBB,
		.name = "DATE_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBC,
		.name = "UID_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBD,
		.name = "UID_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBE,
		.name = "DATA_SERVICE_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xBF,
		.name = "DATA_SERVICE_ADD",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC0,
		.name = "WRITE_32B_IN_DN",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC1,
		.name = "READ_32B_IN_DN",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC2,
		.name = "CUR_CARD_CPZ_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC3,
		.name = "REQUEST_CANCEL",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC4,
		.name = "PLEASE_RETRY",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC5,
		.name = "FLASH_NODE_READ",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC6,
		.name = "FLASH_NODE_WRITE",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC7,
		.name = "FAVORITE_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC8,
		.name = "FAVORITE_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xC9,
		.name = "STARTING_PARENT_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCA,
		.name = "STARTING_PARENT_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCB,
		.name = "CTRVALUE_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCC,
		.name = "CTRVALUE_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCD,
		.name = "CARD_CPZ_CTR_ADD",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCE,
		.name = "CARD_CPZ_CTR_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xCF,
		.name = "CARD_CPZ_CTR_PACKET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD0,
		.name = "FREE_SLOTS_ADDR_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD1,
		.name = "DN_START_PARENT_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD2,
		.name = "DN_START_PARENT_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD3,
		.name = "MEMORYMGMT_LEAVE",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD4,
		.name = "USER_CHANGE_NB_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD5,
		.name = "DESCRIPTION_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD6,
		.name = "USER_CHANGE_NB_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD7,
		.name = "FREE_NB_USR_SLT_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD8,
		.name = "DESCRIPTION_SET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xD9,
		.name = "DEVICE_LOCK",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xDA,
		.name = "MINI_SERIAL_GET",
		.description = "",
		.request = "",
		.response = ""
	},{
		.id = 0xDB,
		.name = "UNLOCK_WITH_PIN",
		.description = "",
		.request = "",
		.response = ""
	}
};

const size_t uma_command_original_size = sizeof(uma_command_original) / sizeof(uma_command_info);
