#include "cimp.h"

int cimp_exe(t_cmd * cmd) {
	for (size_t i = 0; i < g_command_list_size; ++i) {
		if (strcmp(cmd->cmd, g_command_list[i].name) == 0) {
			if (g_command_list[i].func_cmd_ptr == NULL) { // QUIT
				g_cimp->running = 0;
				return (0);
			}
			return (g_command_list[i].func_cmd_ptr(cmd));
		}
	}
	return (-1);
}
