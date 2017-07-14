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
		.description = "Define service the mooltipass should use from now on",
		.request = "String containing the service",
		.response = "1 byte data packet, 0x00 indicates that the Mooltipass doesn't know the context, 0x01 if so and 0x03 that there's no card in the mooltipass"
	},{
		.id = 0xA4,
		.name = "LOGIN_GET",
		.description = "Retrieve the currently selected login for the current context",
		.request = "None or a target login",
		.response = "The login if the user has approved the operation, 1 byte 0x00 packet otherwise."
	},{
		.id = 0xA5,
		.name = "PASSWORD_GET",
		.description = "Retrieve the password for the current context/login couple",
		.request = "Empty",
		.response = "The password if the user approved the operation. 1 byte 0x00 data packet otherwise"
	},{
		.id = 0xA6,
		.name = "LOGIN_SET",
		.description = "Set the login for the current context (either create a credential or select a given credential set)",
		.request = "",
		.response = ""
	},{
		.id = 0xA7,
		.name = "PASSWORD_SET",
		.description = "Set the password for the current login",
		.request = "",
		.response = ""
	},{
		.id = 0xA8,
		.name = "CHECK_PASSWORD",
		.description = "Check the password for the currently selected context and login",
		.request = "",
		.response = ""
	},{
		.id = 0xA9,
		.name = "CONTEXT_ADD",
		.description = "Add a new context inside the mooltipass",
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
		.description = "Get 32 random bytes",
		.request = "",
		.response = ""
	},{
		.id = 0xAD,
		.name = "MEMORYMGMT_ENTER",
		.description = "Enter device in memory management mode after user's approval",
		.request = "",
		.response = ""
	},{
		.id = 0xAE,
		.name = "IMPORT_MEDIA_START",
		.description = "Request for media contents transfer to Mooltipass",
		.request = "",
		.response = ""
	},{
		.id = 0xAF,
		.name = "IMPORT_MEDIA",
		.description = "A bunch of data to store inside the media part of flash, particularly formatted",
		.request = "",
		.response = ""
	},{
		.id = 0xB0,
		.name = "IMPORT_MEDIA_END",
		.description = "Mooltipass message that informs user when the media flash import is finished",
		.request = "N/A",
		.response = ""
	},{
		.id = 0xB1,
		.name = "MOOLTIPASS_PARM_SET",
		.description = "Set one Mooltipass parameter",
		.request = "first byte is the param ID, second is the value",
		.response = ""
	},{
		.id = 0xB2,
		.name = "MOOLTIPASS_PARM_GET",
		.description = "Get parameter from Mooltipass",
		.request = "first byte is the param ID",
		.response = ""
	},{
		.id = 0xB3,
		.name = "CARD_RESET",
		.description = "Reset inserted card",
		.request = "",
		.response = ""
	},{
		.id = 0xB4,
		.name = "READ_CARD_CREDS",
		.description = "Read credentials stored inside the smartcard (confirmation asked from the user)",
		.request = "",
		.response = ""
	},{
		.id = 0xB5,
		.name = "RESERVED",
		.description = "Do not use",
		.request = "N/A",
		.response = "N/A"
	},{
		.id = 0xB6,
		.name = "CARD_LOGIN_SET",
		.description = "Set login stored inside the smartcard, 62bytes max length (confirmation asked to the user)",
		.request = "",
		.response = ""
	},{
		.id = 0xB7,
		.name = "CARD_PASS_SET",
		.description = "Set password stored inside the smartcard, 30bytes max length (confirmation asked to the user)",
		.request = "",
		.response = ""
	},{
		.id = 0xB8,
		.name = "UNKNOWN_CARD_ADD",
		.description = "When an unknown smartcard is inserted, tell the Mooltipass to store it",
		.request = "",
		.response = ""
	},{
		.id = 0xB9,
		.name = "STATUS_GET",
		.description = "Query Mooltipass status",
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
		.description = "Set current date ",
		.request = "16 bits encoding: 15 dn 9 -> Year (2010 + val), 8 dn 5 -> Month, 4 dn 0 -> Day of Month",
		.response = ""
	},{
		.id = 0xBC,
		.name = "UID_SET",
		.description = "Set the Mooltipass UID",
		.request = "",
		.response = ""
	},{
		.id = 0xBD,
		.name = "UID_GET",
		.description = "Get Mooltipass UID",
		.request = "",
		.response = ""
	},{
		.id = 0xBE,
		.name = "DATA_SERVICE_SET",
		.description = "This allows the plugin/application to let the mooltipass know the data service he's currently on",
		.request = "",
		.response = ""
	},{
		.id = 0xBF,
		.name = "DATA_SERVICE_ADD",
		.description = "Add a new data context inside the mooltipass",
		.request = "",
		.response = ""
	},{
		.id = 0xC0,
		.name = "WRITE_32B_IN_DN",
		.description = "Add 32 bytes of data to the current data context",
		.request = "",
		.response = ""
	},{
		.id = 0xC1,
		.name = "READ_32B_IN_DN",
		.description = "After a set data context has been sent, get successive 32bytes data blocks",
		.request = "",
		.response = ""
	},{
		.id = 0xC2,
		.name = "CUR_CARD_CPZ_GET",
		.description = "Ask the CPZ of the currently inserted card, when unknown card is inserted",
		.request = "",
		.response = ""
	},{
		.id = 0xC3,
		.name = "REQUEST_CANCEL",
		.description = "Cancel input request from user",
		.request = "",
		.response = ""
	},{
		.id = 0xC4,
		.name = "PLEASE_RETRY",
		.description = "Message from the mooltipass informing the app to re-send the previous packet",
		.request = "N/A",
		.response = ""
	},{
		.id = 0xC5,
		.name = "FLASH_NODE_READ",
		.description = "Read a user node in flash",
		.request = "",
		.response = ""
	},{
		.id = 0xC6,
		.name = "FLASH_NODE_WRITE",
		.description = "Write a node in flash",
		.request = "",
		.response = ""
	},{
		.id = 0xC7,
		.name = "FAVORITE_GET",
		.description = "Get favorite for current user",
		.request = "",
		.response = ""
	},{
		.id = 0xC8,
		.name = "FAVORITE_SET",
		.description = "Add a favorite for current user,",
		.request = "First byte indicates favId, next 2 the parent addr, next 2 the child addr",
		.response = ""
	},{
		.id = 0xC9,
		.name = "STARTING_PARENT_GET",
		.description = "In management mode, get the address of the starting parent",
		.request = "",
		.response = ""
	},{
		.id = 0xCA,
		.name = "STARTING_PARENT_SET",
		.description = "In management mode, set the address of the starting parent",
		.request = "First two bytes is the new starting parent (LSB first)",
		.response = ""
	},{
		.id = 0xCB,
		.name = "CTRVALUE_GET",
		.description = "In management mode, get the current user CTR value",
		.request = "",
		.response = ""
	},{
		.id = 0xCC,
		.name = "CTRVALUE_SET",
		.description = "In management mode, set the current user CTR value",
		.request = "First three bytes is the new CTR value",
		.response = ""
	},{
		.id = 0xCD,
		.name = "CARD_CPZ_CTR_ADD",
		.description = "Add a known card to the MP, 8 first bytes is the CPZ, next 16 is the CTR nonce",
		.request = "",
		.response = ""
	},{
		.id = 0xCE,
		.name = "CARD_CPZ_CTR_GET",
		.description = "Get all the cpz ctr values for current user",
		.request = "",
		.response = ""
	},{
		.id = 0xCF,
		.name = "CARD_CPZ_CTR_PACKET_EXPORT",
		.description = "Export CPZ CTR values",
		.request = "",
		.response = ""
	},{
		.id = 0xD0,
		.name = "FREE_SLOTS_ADDR_GET",
		.description = "Get addresses of free slots",
		.request = "2 bytes payload indicating the address to start scanning from (in doubt, set 0x00 0x00)",
		.response = ""
	},{
		.id = 0xD1,
		.name = "DN_START_PARENT_GET",
		.description = "In management mode, get the address of the data starting parent",
		.request = "",
		.response = ""
	},{
		.id = 0xD2,
		.name = "DN_START_PARENT_SET",
		.description = "In management mode, set the address of the data starting parent",
		.request = "",
		.response = ""
	},{
		.id = 0xD3,
		.name = "MEMORYMGMT_LEAVE",
		.description = "Leave memory management mode",
		.request = "",
		.response = ""
	},{
		.id = 0xD4,
		.name = "USER_CHANGE_NB_SET",
		.description = "Set user change number",
		.request = "Two bytes payload containing the standard credentials & data change numbers",
		.response = ""
	},{
		.id = 0xD5,
		.name = "DESCRIPTION_GET",
		.description = "Request login description after the user approved credential sending",
		.request = "",
		.response = ""
	},{
		.id = 0xD6,
		.name = "USER_CHANGE_NB_GET",
		.description = "Request the user db change number",
		.request = "",
		.response = ""
	},{
		.id = 0xD7,
		.name = "FREE_NB_USR_SLT_GET",
		.description = "Request the number of slots available for new users",
		.request = "",
		.response = ""
	},{
		.id = 0xD8,
		.name = "DESCRIPTION_SET",
		.description = "Set the description for the current login",
		.request = "",
		.response = ""
	},{
		.id = 0xD9,
		.name = "DEVICE_LOCK",
		.description = "Lock Mooltipass Device",
		.request = "",
		.response = ""
	},{
		.id = 0xDA,
		.name = "MINI_SERIAL_GET",
		.description = "Query the Mini serial number",
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
