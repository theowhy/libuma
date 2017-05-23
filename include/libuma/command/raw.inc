{
	"commands" : [
		{
		    "name" : "PING",
		    "id" : "0xA1",
		    "description" : "Send a 4 bytes payload to mooltipass and it will echo it back",
		    "request_description" : "ping packet with 4 bytes payload",
		    "response_description" : "same packet that the plugin/app sent"
		},
		{
		    "name" : "GET_VERSION",
		    "id" : "0xA2",
		    "description" : "Retrieve mooltipass firmware version",
		    "request_description" : "Request will Empty payload",
		    "response_description" : "The first byte contains the FLASH_CHIP define which specifies how much memory the Mooltipass has. The rest is a string identifying the version in the vX.X format. The Mooltipass Mini has \"_mini\" appended to the version string."
		},
		{
		    "name" : "CONTEXT",
		    "id" : "0xA3"
		},
		{
		    "name" : "GET_LOGIN",
		    "id" : "0xA4"
		},
		{
		    "name" : "GET_PASSWORD",
		    "id" : "0xA5"
		},
		{
		    "name" : "SET_LOGIN",
		    "id" : "0xA6"
		},
		{
		    "name" : "SET_PASSWORD",
		    "id" : "0xA7"
		},
		{
		    "name" : "CHECK_PASSWORD",
		    "id" : "0xA8"
		},
		{
		    "name" : "ADD_CONTEXT",
		    "id" : "0xA9"
		},
		{
		    "name" : "SET_BOOTLOADER_PWD",
		    "id" : "0xAA",
		    "mode" : "std"
		},
		{
		    "name" : "JUMP_TO_BOOTLOADER",
		    "id" : "0xAB",
		    "mode" : "std"
		},
		{
		    "name" : "GET_RANDOM_NUMBER",
		    "id" : "0xAC",
		    "mode" : "std"
		},
		{
		    "name" : "START_MEMORYMGMT",
		    "id" : "0xAD",
		    "mode" : "std"
		},
		{
		    "name" : "IMPORT_MEDIA_START",
		    "id" : "0xAE",
		    "mode" : "std"
		},
		{
		    "name" : "IMPORT_MEDIA",
		    "id" : "0xAF",
		    "mode" : "std"
		},
		{
		    "name" : "IMPORT_MEDIA_END",
		    "id" : "0xB0",
		    "mode" : "std"
		},
		{
		    "name" : "SET_MOOLTIPASS_PARM",
		    "id" : "0xB1",
		    "mode" : "std"
		},
		{
		    "name" : "GET_MOOLTIPASS_PARM",
		    "id" : "0xB2",
		    "mode" : "std"
		},
		{
		    "name" : "RESET_CARD",
		    "id" : "0xB3",
		    "mode" : "std"
		},
		{
		    "name" : "READ_CARD_CREDS",
		    "id" : "0xB4",
		    "mode" : "std"
		},
		{
		    "name" : "RESERVED",
		    "id" : "0xB5",
		    "mode" : "std"
		},
		{
		    "name" : "SET_CARD_LOGIN",
		    "id" : "0xB6",
		    "mode" : "std"
		},
		{
		    "name" : "SET_CARD_PASS",
		    "id" : "0xB7",
		    "mode" : "std"
		},
		{
		    "name" : "ADD_UNKNOWN_CARD",
		    "id" : "0xB8",
		    "mode" : "std"
		},
		{
		    "name" : "STATUS",
		    "id" : "0xB9",
		    "parameters" : "NULL",
		    "response" : {
		        "type" : "integer",
		        "name" : "status"
			}
		},
		{
		    "name" : "FUNCTIONAL_TEST_RES",
		    "id" : "0xBA",
		    "mode" : "std"
		},
		{
		    "name" : "SET_DATE",
		    "id" : "0xBB",
		    "mode" : "std"
		},
		{
		    "name" : "SET_UID",
		    "id" : "0xBC",
		    "mode" : "std"
		},
		{
		    "name" : "GET_UID",
		    "id" : "0xBD",
		    "mode" : "std"
		},
		{
		    "name" : "SET_DATA_SERVICE",
		    "id" : "0xBE",
		    "mode" : "std"
		},
		{
		    "name" : "ADD_DATA_SERVICE",
		    "id" : "0xBF",
		    "mode" : "std"
		},
		{
		    "name" : "WRITE_32B_IN_DN",
		    "id" : "0xC0",
		    "mode" : "management"
		},
		{
		    "name" : "READ_32B_IN_DN",
		    "id" : "0xC1",
		    "mode" : "management"
		},
		{
		    "name" : "GET_CUR_CARD_CPZ",
		    "id" : "0xC2",
		    "mode" : "management"
		},
		{
		    "name" : "CANCEL_REQUEST",
		    "id" : "0xC3",
		    "mode" : "management"
		},
		{
		    "name" : "PLEASE_RETRY",
		    "id" : "0xC4",
		    "mode" : "management"
		},
		{
		    "name" : "READ_FLASH_NODE",
		    "id" : "0xC5",
		    "mode" : "management"
		},
		{
		    "name" : "WRITE_FLASH_NODE",
		    "id" : "0xC6",
		    "mode" : "management"
		},
		{
		    "name" : "GET_FAVORITE",
		    "id" : "0xC7",
		    "mode" : "management"
		},
		{
		    "name" : "SET_FAVORITE",
		    "id" : "0xC8",
		    "mode" : "management"
		},
		{
		    "name" : "GET_STARTING_PARENT",
		    "id" : "0xC9",
		    "mode" : "management"
		},
		{
		    "name" : "SET_STARTING_PARENT",
		    "id" : "0xCA",
		    "mode" : "management"
		},
		{
		    "name" : "GET_CTRVALUE",
		    "id" : "0xCB",
		    "mode" : "management"
		},
		{
		    "name" : "SET_CTRVALUE",
		    "id" : "0xCC",
		    "mode" : "management"
		},
		{
		    "name" : "ADD_CARD_CPZ_CTR",
		    "id" : "0xCD",
		    "mode" : "management"
		},
		{
		    "name" : "GET_CARD_CPZ_CTR",
		    "id" : "0xCE",
		    "mode" : "management"
		},
		{
		    "name" : "CARD_CPZ_CTR_PACKET",
		    "id" : "0xCF",
		    "mode" : "management"
		},
		{
		    "name" : "GET_FREE_SLOTS_ADDR",
		    "id" : "0xD0",
		    "mode" : "management"
		},
		{
		    "name" : "GET_DN_START_PARENT",
		    "id" : "0xD1",
		    "mode" : "management"
		},
		{
		    "name" : "SET_DN_START_PARENT",
		    "id" : "0xD2",
		    "mode" : "management"
		},
		{
		    "name" : "END_MEMORYMGMT",
		    "id" : "0xD3",
		    "mode" : "management"
		},
		{
		    "name" : "SET_USER_CHANGE_NB",
		    "id" : "0xD4",
		    "mode" : "std"
		},
		{
		    "name" : "GET_DESCRIPTION",
		    "id" : "0xD5",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "GET_USER_CHANGE_NB",
		    "id" : "0xD6",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "GET_FREE_NB_USR_SLT",
		    "id" : "0xD7",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "SET_DESCRIPTION",
		    "id" : "0xD8",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "LOCK_DEVICE",
		    "id" : "0xD9",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "GET_MINI_SERIAL",
		    "id" : "0xDA",
		    "mode" : "std",
		    "since" : "1.0"
		},
		{
		    "name" : "UNLOCK_WITH_PIN",
		    "id" : "0xDB",
		    "mode" : "std",
		    "since" : "1.0"
		}
	]
}
