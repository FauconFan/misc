#include "cimp.h"

void cimp_help() {
	for (unsigned int i = 0; i < g_command_list_size; i++) {
		char * tmp = malloc(sizeof(char) * 100);
		strcpy(tmp, g_command_list[i].name);
		if (g_command_list[i].has_name) {
			strcat(tmp, " [PATH]");
		}
		if (g_command_list[i].has_angle) {
			strcat(tmp, " [ANGLE]");
		}
		printf("%s \n", tmp);
		free(tmp);
	}
}
