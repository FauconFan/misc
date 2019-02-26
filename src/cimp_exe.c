#include "cimp.h"

void cimp_exe(t_parser_out * cmd) {
	if (strstr(cmd->cmd, "help")) {
		cimp_help();
	}
	else if (strstr(cmd->cmd, "open")) {
		char * errno_str = NULL;
		cimp_open(cmd->name_file, &errno_str);
		if (errno_str)
			printf("Something went wrong %s\n", errno_str);
	}
	else if (strstr(cmd->cmd, "list")) {
		cimp_list();
	}
	else if (strstr(cmd->cmd, "rotate")) {
		cimp_rotate(cmd->angle);
	}
	else if (strstr(cmd->cmd, "sym_verti")) {
		cimp_sym_verti();
	}
	else if (strstr(cmd->cmd, "sym_hori")) {
		cimp_sym_hori();
	}
	else if (strstr(cmd->cmd, "close")) {
		cimp_close();
	}
	else if (strstr(cmd->cmd, "QUIT")) {
		exit(0);
	}
}
