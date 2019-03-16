#include "cimp.h"

int cimp_help(t_cmd * cmd) {
	int max_name;

	(void) cmd;
	max_name = 0;
	for (size_t i = 0; i < g_command_list_size; i++) {
		int tmp = strlen(g_command_list[i].name);
		if (tmp > max_name)
			max_name = tmp;
	}
	max_name++;
	for (size_t i = 0; i < g_command_list_size; i++) {
		printf("%-*s", max_name, g_command_list[i].name);
		if (g_command_list[i].need_name) {
			printf(" [PATH]");
		}
		if (g_command_list[i].need_angle) {
			printf(" [ANGLE]");
		}
		printf("\n");
	}
	return (0);
}
