#include "cimp.h"

/**
 * Initialise l'environnement, charge SDL et alloue la structure globale g_cimp
 */
int             cimp_init() {
	if (g_cimp)
		return (0);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (2);
	}
	if ((g_cimp = (t_cimp *) malloc(sizeof(t_cimp))) == NULL)
		return (1);

	g_cimp->screen  = NULL;
	g_cimp->running = 1;
	return (0);
}

/**
 * Libère les ressources, et du programme et de la librairie SDL
 */
void            cimp_end() {
	if (g_cimp) {
		if (g_cimp->screen)
			cimp_end_screen(g_cimp->screen);
		free(g_cimp);
		g_cimp = NULL;
		SDL_Quit();
	}
}
