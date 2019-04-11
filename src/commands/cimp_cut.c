#include "cimp.h"

/**Une fonction qui copie la partie de l'image selectionnee et la remplace par du noir.
 * Renvoie 0 en cas de succes et -1 sinon. **/
t_rc_cmd cimp_cut(t_cmd * cmd) {
	t_rc_cmd ret_copy;

	if ((ret_copy = cimp_copy(cmd)) != OK)
		return (ret_copy);

	SDL_Rect rect;
	if (cmd->rect.x != -1 && cmd->rect.y != -1 && cmd->rect.w != -1 && cmd->rect.h != -1) {
		rect = cmd->rect;
	}
	else {
		if (g_cimp->select == NULL) {
			printf("Pas de zone selectionnee : copie impossible \n");
			return FAIL;
		}
		rect = g_cimp->select->surface;
	}
	SDL_Surface * surface;
	surface = g_cimp->screen[g_cimp->focus]->buff_screen;
	Uint32 color = SDL_MapRGBA(surface->format, 0, 0, 0, 0);
	if (SDL_FillRect(surface, &rect, color) < 0)
		return ABORT;

	return OK;
}
