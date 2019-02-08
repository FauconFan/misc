
#include "cimp.h"

// Fonction temporaire pour tester si le système en place marche bien.
void test(int id)
{
	char	*errno_str = NULL;

	if (id == 0 && g_cimp->screen == NULL)
	{
		cimp_open("images/untitled3.bmp", &errno_str);
		cimp_sym_verti();
		
		if (errno_str)
			printf("Something went wrong %s\n", errno_str);
	}
	else if (id == 1 && g_cimp->screen)
	{
		cimp_close(g_cimp->screen);
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
int main(void)
{
	char			*line;
	int				running;

	if (cimp_init())
	{
		printf("Something went terribly wrong\n");
		return (1);
	}
	running = 1;
	while (running && (line = cimp_readline()) != NULL)
	{
		if (strcmp(line, "QUIT") == 0)
			running = 0;
		else if (strcmp(line, "init") == 0) // harcoded test
			test(0);
		else if (strcmp(line, "close") == 0) // harcoded test
			test(1);
		else
		{
			printf("The line entered is : %s\n", line);
			printf("Enter 'QUIT' to exit the program properly\n");
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
}
