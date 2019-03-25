#include "cimp.h"

/**
 * Initialise l'environnement, charge SDL et alloue la structure globale g_cimp
 */
int             cimp_init() {
	if (g_cimp)
		return (0);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL couldn't initialize ! SDL_Error: %s\n", SDL_GetError());
		return (2);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != (IMG_INIT_JPG | IMG_INIT_PNG)) {
		printf("SDL_IMG couldn't initialize ! IMG_Error: %s\n", IMG_GetError());
		return (2);
	}
	if ((g_cimp = (t_cimp *) malloc(sizeof(t_cimp))) == NULL)
		return (1);

	g_cimp->screen      = NULL;
	g_cimp->select      = NULL;
	g_cimp->event       = init_cimp_event();
	g_cimp->running     = 1;
	g_cimp->copy_buffer = NULL;
	return (0);
}

/**
 * Libère les ressources, et du programme et de la librairie SDL
 */
void            cimp_end() {
	if (g_cimp) {
		if (g_cimp->screen)
<<<<<<< HEAD
			cimp_end_screen(g_cimp->screen);
		if (g_cimp->copy_buffer)
			SDL_FreeSurface(g_cimp->copy_buffer);
=======
			cimp_screen_end(g_cimp->screen);
>>>>>>> a0feaab77d832127e8028fca2fc584d7f27d912a
		free_cimp_event(g_cimp->event);
		cimp_end_select(g_cimp->select);
		free(g_cimp);
		g_cimp = NULL;
		IMG_Quit();
		SDL_Quit();
	}
}
