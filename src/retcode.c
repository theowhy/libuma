
#include <libuma/retcode.h>
#include <stdlib.h>

struct rc_info {
	size_t id;
	char const *name;
	char const *description;
	char const *help;

};

struct rc_module {
	size_t id;
	char const *name;
	struct rc_info *retcodes;
};

static struct rc_info generic_rc[] = {
	{UMA_SUCCESS, "SUCCESS", "Everything went as excepted", ""},
	{UMA_ERROR_BAD_ARGS, "ERROR_BAD_ARGS", "Bad arguments were given to API call", "This error is a most likely an error in API usage. Build the software in Debug and look for assertions"},
	{0}
};

static struct rc_module rc_modules[] = {
	{
		.id = 0,
		.name = "GENERIC",
		.retcodes = generic_rc
	},
	{0}
};

const char * error_info_get(uma_ret_code return_code, const char ** const help) {
	size_t module_id = return_code & 0xFFFF0000;

	for(size_t i = 0; rc_modules[i].name != NULL; i++) {
		struct rc_module *module = (&rc_modules[i]);

		if(module->id == module_id) {
			struct rc_info * retcode_infos = (module->retcodes);

			for(size_t j = 0; retcode_infos[j].name != NULL; j++) {
				struct rc_info *retcode_info = (&retcode_infos[j]);

				if(retcode_info->id == return_code) {

					if((help != NULL) && (retcode_info->help != NULL)) {
						(*help) = retcode_info->help;
					}
					return retcode_info->description;
				}
			}
		}
	}
	return NULL;
}
