#include "cimp.h"

// Fonction temporaire pour tester si le système en place marche bien.
void test(int id) {
	char * errno_str = NULL;

	if (id == 0 && g_cimp->screen == NULL) {
		g_cimp->screen = cimp_init_screen("images/untitled3.bmp", &errno_str);
		if (errno_str)
			printf("Something went wrong %s\n", errno_str);
	}
	else if (id == 1 && g_cimp->screen) {
		cimp_end_screen(g_cimp->screen);
		g_cimp->screen = NULL;
	}
}

/**
 * main gère la boucle principale du programme sous forme d'un REPL.
 * REPL := Read Eval Print Loop
 * Read : appel de la fonction cimp_readline
 * Eval : interprétation pour le programme
 * Print : actualisation de l'interface utilisateur
 * Loop : on recommence
 * @return  0
 */
int main(void) {
	char * line;
	int running;
	t_error_parser error;
	t_parser_out * cmd;

	if (cimp_init()) {
		printf("Something went terribly wrong\n");
		return (1);
	}
	running = 1;
	while (running && (line = cimp_readline()) != NULL) {
		if (strcmp(line, "QUIT") == 0) {
			running = 0;
		}
		else if (strcmp(line, "init") == 0) { // harcoded test
			test(0);
		}
		else if (strcmp(line, "close") == 0) { // harcoded test
			test(1);
		}
		else {
			cmd = parse_line(line, &error);
			if (cmd != NULL) {
				printf("DAMN nous avons parser une ligne ! cmd : %s name_file : %s angle : %d \n",
				  cmd->cmd, cmd->name_file, cmd->angle);
				free_p_out(cmd);
			}
			else {
				printf("Attention une erreur est apparue ! ERREUR : \n %s \n", get_error(error));
				printf("The line entered is : %s\n", line);
				printf("Enter 'QUIT' to exit the program properly\n");
			}
		}
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
