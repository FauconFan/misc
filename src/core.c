#include "cimp.h"

void treat_line(char * line) {
	t_cmd * cmd;

	cmd = parser(line);
	if (cmd != NULL) {
		if (cimp_exe(cmd) == -1) {
			printf("Internal program error !!!\n");
			printf("Please contact maintainers !!!\n");
		}
		cmd_free(cmd);
	}
}

void handle_line() {
	char * line = NULL;

	line = child_getline();
	if (line != NULL) {
		treat_line(line);
		free(line);
		line = NULL;

		if (g_cimp->running) {
			child_send_ok();
		}
	}
}

void core() {
	while (g_cimp->running) {
		handle_line();
		usleep(30); // 30 ms arbitrary
		cimp_update_screen(g_cimp->screen);
	}
}
