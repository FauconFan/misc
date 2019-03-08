#include "cimp.h"

void cimp_exe(t_cmd * cmd) {
	if (strcmp(cmd->cmd, "help") == 0) {
		cimp_help();
	}
	else if (strcmp(cmd->cmd, "open") == 0) {
		char * errno_str = NULL;
		cimp_open(cmd->name_file, &errno_str);
		if (errno_str)
			printf("Something went wrong %s\n", errno_str);
	}
	else if (strcmp(cmd->cmd, "list") == 0) {
		cimp_list();
	}
	else if (strcmp(cmd->cmd, "rotate") == 0) {
		cimp_rotate(cmd->angle);
	}
	else if (strcmp(cmd->cmd, "sym_verti") == 0) {
		cimp_sym_verti();
	}
	else if (strcmp(cmd->cmd, "sym_hori") == 0) {
		cimp_sym_hori();
	}
	else if (strcmp(cmd->cmd, "close") == 0) {
		cimp_close();
	}
	else if (strcmp(cmd->cmd, "QUIT") == 0) {
		g_cimp->running = 0;
	}
}
