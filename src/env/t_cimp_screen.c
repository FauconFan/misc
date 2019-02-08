
#include "cimp.h"

/**
 * cimp_init_screen est la fonction qui crée une instance de t_cimp_screen
 * à partir d'un chemin et renvoie un pointeur vers la structure si tout
 * s'est bien passé, sinon renvoie null et stocke un message d'erreur dans errno_str.
 * Cette fonction fait tous les checks d'instanciation à savoir :
 *  - construire le chemin absolu
 *  - ouvrir le fichier est construire un SDL_Surface.
 *  - créer la SDL_Window associé
 *  - construire enfin la structure et tout stocker
 * @param  path_bmp  le chemin du bmp (relative, absolu avec ~/ en préfixe)
 * @param  errno_str un pointeur vers une chaîne de charactères
 * @return           un pointeur vers la structure allouée
 */
t_cimp_screen		*cimp_init_screen(
						char *path_bmp,
						char **errno_str)
{
	t_cimp_screen	*sc;
	SDL_Window		*win;
	SDL_Surface		*surf;
	char			*path;

	if ((path = normalize_path(path_bmp)) == NULL)
	{
		*errno_str = NOT_A_PATH;
		return (NULL);
	}
	if ((surf = SDL_LoadBMP(path)) == NULL)
	{
		*errno_str = (char *)SDL_GetError();
		free(path);
		return (NULL);
	}
	if (NULL == (win = SDL_CreateWindow(basename(path),
						SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED,
						surf->w,
						surf->h,
						SDL_WINDOW_SHOWN)))
	{
		*errno_str = (char *)SDL_GetError();
		free(path);
		SDL_FreeSurface(surf);
		return (NULL);
	}
	if ((sc = (t_cimp_screen *)malloc(sizeof(t_cimp_screen))) == NULL)
	{
		*errno_str = MALLOC_FAIL;
		free(path);
		SDL_FreeSurface(surf);
		SDL_DestroyWindow(win);
		return (NULL);
	}
	sc->window = win;
	sc->buff_screen = surf;
	sc->original_path = path;
	cimp_update_screen(sc);
	return (sc);
}

/**
 * cimp_end_screen libère les ressources associé à cette instance de t_cimp_screen
 * @param  sc l'instance de t_cimp_screen
 */
void				cimp_end_screen(t_cimp_screen *sc)
{
	free(sc->original_path);
	SDL_FreeSurface(sc->buff_screen);
	SDL_DestroyWindow(sc->window);
	free(sc);
}

/**
 * update the SDL window using the buffered SDL_Surface.
 * @param  screen the cimp screen pointer
 * @return        nothing
 */
void				cimp_update_screen(t_cimp_screen *screen)
{
	SDL_Rect		full_rect;

	if (screen == NULL)
		return ;

	full_rect.x = 0;
	full_rect.y = 0;
	full_rect.w = screen->buff_screen->w;
	full_rect.h = screen->buff_screen->h;
	SDL_BlitSurface(screen->buff_screen, &full_rect, SDL_GetWindowSurface(screen->window), NULL);
	SDL_UpdateWindowSurface(screen->window);
}
