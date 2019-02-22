#include "cimp.h"

void cimp_help() {
	int max_name = 0;

	for (size_t i = 0; i < g_command_list_size; i++) {
		max_name = max(max_name, strlen(g_command_list[i].name));
	}
	max_name++;
	for (size_t i = 0; i < g_command_list_size; i++) {
		printf("%-*s", max_name, g_command_list[i].name);
		if (g_command_list[i].has_name) {
			printf(" [PATH]");
		}
		if (g_command_list[i].has_angle) {
			printf(" [ANGLE]");
		}
		printf("\n");
	}
}
