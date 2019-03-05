#include "cimp.h"

/**
 * main gère la boucle principale du programme sous forme d'un REPL.
 * REPL := Read Eval Print Loop
 * Read : appel de la fonction cimp_readline
 * Eval : interprétation pour le programme
 * Print : actualisation de l'interface utilisateur
 * Loop : on recommence
 * @return  0
 */

static void analyse(char * line, int * running) {
	t_error_parser error;
	t_parser_out * cmd = parse_line(line, &error);

	if (cmd != NULL) {
		printf("DAMN nous avons parser une ligne ! cmd : %s name_file : %s angle : %d \n",
		  cmd->cmd, cmd->name_file, cmd->angle);
		*running = cimp_exe(cmd);
		cimp_update_screen(g_cimp->screen);
		free_p_out(cmd);
	}
	else {
		printf("Attention une erreur est apparue ! ERREUR : \n %s \n", get_error(error));
		printf("The line entered is : %s\n", line);
		printf("Enter 'QUIT' to exit the program properly\n");
	}
}

static char * getline_from_child() {
	char * line = NULL;
	size_t len  = 0;

	while (read(g_cimp->fd_readline, &len, sizeof(len)) == -1)
		usleep(30);  // 30 ms
	line = (char *) malloc(sizeof(char) * (len + 1));
	memset(line, 0, len + 1);
	read(g_cimp->fd_readline, line, len);
	return (line);
}

int main(void) {
	char * line;
	int running;

	if (cimp_init()) {
		printf("Something went terribly wrong\n");
		return (1);
	}
	setup_child();
	running = 1;
	while (running && (line = getline_from_child()) != NULL) {
		analyse(line, &running);
		free(line);
		line = NULL;
		size_t tmp = 0;
		write(g_cimp->fd_callback, &tmp, sizeof(tmp));
	}
	if (line)
		free(line);
	if (running)
		printf("cimp error feedback : %s\n", strerror(errno));
	cimp_end();
	return (0);
} /* main */
