#include "cimp.h"

/** Une fonction qui stocke dans le champs copy_buffer de g_cimp la partie de l'image designee
 * par l'argument rect passe a la commande.
 * Renvoie 0 en cas de succes et en cas d'echec ou si aucune image n'es ouverte renvoie -1**/
int cimp_copy(t_cmd * cmd) {
	if (!g_cimp->screen) {
		printf("Pas d'image ouverte : la copie est impossible\n");
		return -1;
	}

	SDL_Surface * surface;
	if ( (surface = SDL_CreateRGBSurface(0, cmd->rect.w, cmd->rect.h, 32, 0, 0, 0, 0)) == NULL)
		return -1;

	Uint32 * pixels_dest, * pixels_src;
	SDL_LockSurface(surface);
	pixels_dest = surface->pixels;
	pixels_src  = g_cimp->screen->buff_screen->pixels;
	for (int i = cmd->rect.x; i < cmd->rect.x + cmd->rect.w; i++) {
		for (int j = cmd->rect.y; j < cmd->rect.y + cmd->rect.h; j++)
			pixels_dest[i * surface->w + j] = pixels_src[i * g_cimp->screen->buff_screen->w + j];
	}
	SDL_UnlockSurface(surface);

	g_cimp->copy_buffer = surface;

	return 0;
}

/**Une fonction qui colle la surface stockee dans copy_buffer a partir des coordonnes x0 y0
 * passees en arguments.
 * Renvoie 0 en cas de succes et -1 sinon en affichant un message d'erreur. **/
int cimp_paste(t_cmd * cmd) {
	if (!g_cimp->screen) {
		printf("Pas d'image ouverte : le collage est impossible\n");
		return -1;
	}
	else if (!g_cimp->copy_buffer) {
		printf("Rien n'a ete copie : le collage est impossible\n");
		return -1;
	}

	SDL_Surface * surface_src, * surface_dest;
	surface_src  = g_cimp->copy_buffer;
	surface_dest = g_cimp->screen->buff_screen;

	Uint32 * pixels_dest, * pixels_src;
	SDL_LockSurface(surface_dest);
	pixels_dest = surface_dest->pixels;
	pixels_src  = surface_src->pixels;
	for (int i = cmd->x0; i < cmd->x0 + surface_src->w; i++) {
		for (int j = cmd->y0; j < cmd->y0 + surface_src->h; j++)
			pixels_dest[i * surface_dest->w + j] = pixels_src[i * surface_src->w + j];
	}
	SDL_UnlockSurface(surface_dest);


	return 0;
}

/**Une fonction qui copie la partie de l'image selectionnee et la re place par du bleu.
 * Renvoie 0 en cas de succes et -1 sinon. **/
int cimp_cut(t_cmd * cmd) {
	if (cimp_copy(cmd) < 0)
		return -1;

	SDL_Surface * surface;
	surface = g_cimp->screen->buff_screen;
	Uint32 color = SDL_MapRGBA(surface->format, 0, 0, 0, 255);
	if (SDL_FillRect(surface, &cmd->rect, color) < 0)
		return -1;

	return 0;
}
