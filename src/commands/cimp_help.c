#include "cimp.h"

void cimp_help() {
<<<<<<< HEAD
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
=======
	int max_name = 0;

	for (size_t i = 0; i < g_command_list_size; i++) {
		int tmp = strlen(g_command_list[i].name);
		if (tmp > max_name)
			max_name = tmp;
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
>>>>>>> 37d3ce710378f70d00f91ff8ecc57b2dc7d5b405
	}
}
