#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

/**
 * Ici sont définies les structures standards utilisées dans le programme.
 */

typedef struct          s_cimp_screen {
	SDL_Window *  window;
	SDL_Surface * buff_screen;
	char *        original_path;
}                       t_cimp_screen;

typedef struct          s_cimp {
	t_cimp_screen * screen;
}                       t_cimp;

/**
 * Ici est définie la variable globale g_cimp qui stocke l'instance de notre programme.
 */

extern t_cimp * g_cimp;

#endif // ifndef TYPEDEFS_H
