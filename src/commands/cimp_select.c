#include "cimp.h"


/**Une fonction qui cree la zone de selection associee au rectangle rect.
* Si une selectionexiste deja on met a jour les donnees du rectangle  **/
int cimp_select(SDL_Rect rect, char ** errno_str) {
	if (g_cimp->screen == NULL) {
		printf("Pas d'ecran ouvert donc pas de selection possible \n");
		return -1;
	}
	if (g_cimp->select != NULL) {
		g_cimp->select->surface = rect;

		/**
		 * SDL_LockSurface(g_cimp->screen->buff_screen);
		 * Uint32 *pixels = g_cimp->screen->buff_screen->pixels;
		 * int w_surface = g_cimp->screen->buff_screen->w;
		 * for(int i = rect.x; i < rect.x+rect.w; i++){
		 *  for(int j = rect.y; j <rect.y+rect.h; j++)
		 *      pixels[i * w_surface + j] = 0xFF0000FF;
		 *  }
		 * SDL_UnlockSurface(g_cimp->screen->buff_screen);
		 **/
		return 0;
	}

	t_cimp_select * selection = cimp_init_select(rect, errno_str);

	if (selection == NULL) {
		return -1;
	}

	g_cimp->select = selection;

	// ON dessine le rectangle correspondant a la selection

	/**
	 * SDL_LockSurface(g_cimp->screen->buff_screen);
	 * Uint32 *pixels = g_cimp->screen->buff_screen->pixels;
	 * int w_surface = g_cimp->screen->buff_screen->w;
	 * for(int i = rect.x; i < rect.x+rect.w; i++){
	 *  for(int j = rect.y; j <rect.y+rect.h; j++)
	 *      pixels[i * w_surface + j] = 0xFF0000FF;
	 *  }
	 * SDL_UnlockSurface(g_cimp->screen->buff_screen);
	 **/
	return 0;
}

/** Une fonction aui libere la memoire associee a une selection,
 * mets a jour le champ correspondant dans g_cimp.**/
void cimp_unselect() {
	cimp_end_select(g_cimp->select);
	g_cimp->select = NULL;
}
