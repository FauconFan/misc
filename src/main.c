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

int main(void) {
	char * line;
	int running;

	initialize_readline();
	if (cimp_init()) {
		printf("Something went terribly wrong\n");
		return (1);
	}
	running = 1;
	while (running && (line = readline("cimp>>")) != NULL) {
		add_history(line);
		analyse(line, &running);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (running)
		printf("cimp error feedback : %s\n", strerror(errno));
	cimp_end();
	return (0);
} /* main */
