#include "cimp.h"

void treat_line(char * line) {
	t_cmd * cmd;

	cmd = parser(line);
	if (cmd != NULL) {
		switch (cimp_exe(cmd)) {
			case OK:
				break;
			case FAIL:
				printf("Fail command...\n");
				break;
			case ABORT:
				printf("Internal program error !!!\n");
				printf("Please contact maintainers !!!\n");
				break;
		}
		cmd_free(cmd);
	}
} /* treat_line */

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
		cimp_screen_update(g_cimp->screen);
		usleep(30); // 30 ms arbitrary
	}
}
