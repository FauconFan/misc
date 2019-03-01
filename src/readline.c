#include "cimp.h"

int nb_completions = 0;
char ** completions;

/* Fonctions internes à readline */
char ** fileman_completion(const char * com, int start, int end);
char * command_generator(const char * com, int num);
/*********************************/

void initialisation_tab_completion() {
	nb_completions = g_command_list_size;
	completions    = malloc(sizeof(char *) * nb_completions);
	if (completions != NULL) {
		for (size_t i = 0; i < g_command_list_size; i++) {
			completions[i] = malloc(sizeof(char) * (strlen(g_command_list[i].name) + 1));
			if (completions[i]) {
				strncpy(completions[i], g_command_list[i].name, strlen(g_command_list[i].name));
			}
			else {
				printf("Erreur lors de la création du tableau de complétion");
			}
		}
	}
	else {
		printf("Something went terrebly wrong with readline initialisation");
	}
}

int initialize_readline() {
	initialisation_tab_completion();
	using_history();// initialisation de l'utilisation de la librairie history de readline
	rl_readline_name = "mon prompt>>";

	/* explicite la complÃ©tion souhaitÃ©e */
	rl_attempted_completion_function = fileman_completion;
	return 0;
}

/* com : tout ce que l'utilisateur a dÃ©jÃ  Ã©crit sur la ligne de commande
 * start, end : les indices de dÃ©but et de fin du mot sur lequel TAB a Ã©tÃ© lancÃ© */
char ** fileman_completion(const char * com, int start, int end) {
	char ** matches;

	matches = (char **) NULL; /* assure la complÃ©tion par dÃ©faut */

	/* si c'est le premier mot de la ligne de commande, on l'analyse;
	 * sinon on utilise l'analyse par dÃ©faut */
	if (start == 0)
		matches = rl_completion_matches(com, command_generator);

	/* cast de end en void car ne peut être enlevé du prototype
	 *  de fonction et n'est pas utilisé pour l'instant donc ne passe pas cppcheck */
	(void) end;

	return (matches);
}

/* fonction qui engendre les complÃ©tions possibles :
 * Ã  chaque num >= 0 correspond une complÃ©tion;
 * la fin de la liste des complÃ©tions est donnÃ©e par NULL
 *
 * ici on complÃ¨te si c'est un prÃ©fixe de "toto" ou de "turlututu",
 * sinon c'est la complÃ©tion par dÃ©faut */
char * command_generator(const char * com, int num) {
	/* Ã  l'entrÃ©e de cette fonction : com est le dÃ©but dÃ©jÃ  Ã©crit de la commande,
	 * on est en train de chercher la complÃ©tion numÃ©ro num */
	static int indice, len;


	/* si c'est la premiÃ¨re complÃ©tion qu'on cherche, on dit qu'on va chercher Ã  partir
	 * de la premiere case du tableau completion et on garde en mÃ©moire la longueur
	 * du texte tapÃ© */
	if (num == 0) {
		indice = 0;
		len    = strlen(com);
	}

	/* on renvoie une complÃ©tion de prÃ©fixe le dÃ©but de la commande Ã©crite */
	while (indice < nb_completions) {
		char * completion = completions[indice++];

		if (strncmp(completion, com, len) == 0)
			return dupstr(completion);
	}

	/* est renvoyÃ© quand num est > au numÃ©ro de la derniÃ¨re complÃ©tion
	 * automatique */
	return NULL;
}
