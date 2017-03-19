#include <libuma/device/handler.h>
#include <libuma/init.h>
#include <stdio.h>

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	uma_Mooltipass_list mooltipass_list = {NULL, 0};

	uma_init();
	uma_device_list(&mooltipass_list);

	if(mooltipass_list.count == 0) {
		printf("No mooltipass detected\n");

		uma_device_list_release(&mooltipass_list);
		uma_shutdown();

		return 1;
	}
	printf("%zu mooltipass detected\n", mooltipass_list.count);

	for(size_t i = 0; i < mooltipass_list.count; i++) {
		printf("Mooltipass %zu\n", i);
		printf("==============\n");
		uma_device_info_print(mooltipass_list.devices[i]);
	}
	uma_device_list_release(&mooltipass_list);

	uma_shutdown();

	return 0;
}
