#include "cimp.h"

/** Une fonction qui stocke dans le champs copy_buffer de g_cimp la partie de l'image designee
 * par l'argument rect passe a la commande.
 *  Dans le cas ou le rectangle sors de l'image on selectionne le plus grand rectangle possible dans l'image
 * Renvoie 0 en cas de succes et en cas d'echec ou si aucune image n'es ouverte renvoie -1**/
int cimp_copy(t_cmd * cmd) {
	if (!g_cimp->screen) {
		printf("Pas d'image ouverte : la copie est impossible\n");
		return -1;
	}

	// Si les coordonnes initiales du rectangles sont hors de l'image on echoue
	if (g_cimp->screen->buff_screen->w < cmd->rect.x ||
	  g_cimp->screen->buff_screen->h < cmd->rect.y ||
	  cmd->rect.x < 0 || cmd->rect.y < 0 ||
	  cmd->rect.w < 0 || cmd->rect.h < 0 ||
	  cmd->rect.w + cmd->rect.x > g_cimp->screen->buff_screen->w ||
	  cmd->rect.h + cmd->rect.y > g_cimp->screen->buff_screen->h)
	{
		printf("La zone a copiee est hors de l'image\n");
		return -1;
	}
	if (g_cimp->copy_buffer) {
		SDL_FreeSurface(g_cimp->copy_buffer);
		g_cimp->copy_buffer = NULL;
	}

	SDL_Surface * surface;
	if ( (surface = SDL_CreateRGBSurface(0, cmd->rect.w, cmd->rect.h, 32, 0, 0, 0, 0)) == NULL)
		return -1;

	Uint32 * pixels_dest, * pixels_src;
	SDL_LockSurface(surface);
	pixels_dest = (Uint32 *) surface->pixels;
	pixels_src  = (Uint32 *) g_cimp->screen->buff_screen->pixels;
	for (int i = cmd->rect.x; i < cmd->rect.x + cmd->rect.w; i++) {
		for (int j = cmd->rect.y; j < cmd->rect.y + cmd->rect.h; j++)
			pixels_dest[(j - cmd->rect.y) * surface->w
			+ (i - cmd->rect.x)] = pixels_src[j * g_cimp->screen->buff_screen->w + i];
	}
	SDL_UnlockSurface(surface);

	g_cimp->copy_buffer = surface;

	return 0;
} /* cimp_copy */

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

	if (cmd->x0 < 0 || cmd->y0 < 0 ||
	  cmd->x0 > g_cimp->screen->buff_screen->w ||
	  cmd->y0 > g_cimp->screen->buff_screen->h)
	{
		printf("Coordonees en dehors de l'image : collage impossible\n");
		return -1;
	}

	SDL_Surface * surface_src, * surface_dest;
	surface_src  = g_cimp->copy_buffer;
	surface_dest = g_cimp->screen->buff_screen;

	Uint32 * pixels_dest, * pixels_src;
	SDL_LockSurface(surface_dest);
	pixels_dest = (Uint32 *) surface_dest->pixels;
	pixels_src  = (Uint32 *) surface_src->pixels;
	for (int i = cmd->x0; i < min(cmd->x0 + surface_src->w, surface_dest->w); i++) {
		for (int j = cmd->y0; j < min(cmd->y0 + surface_src->h, surface_dest->h); j++)
			pixels_dest[j * surface_dest->w
			+ i] = pixels_src[(j - cmd->y0) * surface_src->w + (i - cmd->x0)];
	}
	SDL_UnlockSurface(surface_dest);


	return 0;
} /* cimp_paste */

/**Une fonction qui copie la partie de l'image selectionnee et la remplace par du noir.
 * Renvoie 0 en cas de succes et -1 sinon. **/
int cimp_cut(t_cmd * cmd) {
	if (cimp_copy(cmd) < 0)
		return -1;

	SDL_Surface * surface;
	surface = g_cimp->screen->buff_screen;
	Uint32 color = SDL_MapRGBA(surface->format, 0, 0, 0, 0);
	if (SDL_FillRect(surface, &cmd->rect, color) < 0)
		return -1;

	return 0;
}
