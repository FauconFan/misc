
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
int main(void)
{
	char	*line;
	int		running;

	running = 1;
	while (running && (line = cimp_readline()) != NULL)
	{
		if (strcmp(line, "QUIT") == 0)
			running = 0;
		else
		{
			printf("The line entered is :\n%s\n", line);
			printf("Enter 'QUIT' to exit the program properly\n");
		}
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (running)
		printf("cimp error feedback : %s\n", strerror(errno));
	return (0);
}
