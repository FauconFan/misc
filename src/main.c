#include "cimp.h"

static void treat_line(char * line) {
	t_error_parser error;
	t_parser_out * cmd = parse_line(line, &error);

	if (cmd != NULL) {
		printf(
		  "DAMN nous avons parser une ligne ! \n{ cmd : %s\n  name_file : %s\n  angle : %d \n rect : x=%d y=%d w=%d h=%d} \n",
		  cmd->cmd, cmd->name_file, cmd->angle, cmd->rect.x, cmd->rect.y, cmd->rect.w, cmd->rect.h);
		if (g_cimp->select == NULL) {
			printf("Pas de selection courante \n");
		}
		else {
			printf("Selection courrante :  x=%d y=%d w=%d h=%d\n", g_cimp->select->surface.x,
			  g_cimp->select->surface.y, g_cimp->select->surface.w, g_cimp->select->surface.h);
		}
		cimp_exe(cmd);
		free_p_out(cmd);
	}
	else {
		printf("Attention une erreur est apparue ! ERREUR : \n %s \n", get_error(error));
		printf("The line entered is : %s\n", line);
		printf("Enter 'QUIT' to exit the program properly\n");
	}
}

static void handle_line() {
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

int main(void) {
	if (setup_child()) {
		return (1);
	}
	if (cimp_init()) {
		printf("Something went terribly wrong\n");
		return (1);
	}
	while (g_cimp->running) {
		handle_line();
		usleep(30); // 30 ms arbitrary
		cimp_update_screen(g_cimp->screen);
	}
	child_send_stop();
	cimp_end();
	return (0);
} /* main */
