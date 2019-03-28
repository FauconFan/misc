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

	SDL_Rect rect;
	SDL_Surface * surface_src, * surface_dest;
	surface_src = g_cimp->screen->buff_screen;

	if (cmd->rect.x != -1 && cmd->rect.y != -1 && cmd->rect.w != -1 && cmd->rect.h != -1) {
		rect = cmd->rect;
	}
	else {
		if (g_cimp->select == NULL) {
			printf("Pas de zone selectionnee : copie impossible \n");
			return -1;
		}
		rect = g_cimp->select->surface;
	}

	// Si les coordonnes initiales du rectangles sont hors de l'image on echoue
	if (surface_src->w < rect.x ||
	  surface_src->h < rect.y ||
	  rect.x < 0 || rect.y < 0 ||
	  rect.w < 0 || rect.h < 0 ||
	  rect.w + rect.x > surface_src->w ||
	  rect.h + rect.y > surface_src->h)
	{
		printf("La zone a copiee est hors de l'image\n");
		return -1;
	}

	// Si un copy_buffer est deja present on le libere pour un en creer un nouveau
	if (g_cimp->copy_buffer) {
		SDL_FreeSurface(g_cimp->copy_buffer);
		g_cimp->copy_buffer = NULL;
	}

	// On cree notre nouvelle surface puis on la remplit
	if ( (surface_dest = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0)) == NULL)
		return -1;

	Uint32 * pixels_dest, * pixels_src;

	if (SDL_MUSTLOCK(surface_dest))
		SDL_LockSurface(surface_dest);

	pixels_dest = (Uint32 *) surface_dest->pixels;
	pixels_src  = (Uint32 *) surface_src->pixels;
	for (int i = rect.x; i < rect.x + rect.w; i++) {
		for (int j = rect.y; j < rect.y + rect.h; j++)
			pixels_dest[(j - rect.y) * surface_dest->w
			+ (i - rect.x)] = pixels_src[j * surface_src->w + i];
	}
	if (SDL_MUSTLOCK(surface_dest))
		SDL_UnlockSurface(surface_dest);

	g_cimp->copy_buffer = surface_dest;

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
	if (!g_cimp->copy_buffer) {
		printf("Rien n'a ete copie : le collage est impossible\n");
		return -1;
	}

	// Si les coordonnes sont hors de l'ecran on echoue
	if (cmd->point.x < 0 || cmd->point.y < 0 ||
	  cmd->point.x > g_cimp->screen->buff_screen->w ||
	  cmd->point.y > g_cimp->screen->buff_screen->h)
	{
		printf("Coordonees en dehors de l'image : collage impossible\n");
		return -1;
	}

	SDL_Surface * surface_src, * surface_dest;
	surface_src  = g_cimp->copy_buffer;
	surface_dest = g_cimp->screen->buff_screen;

	Uint32 * pixels_dest, * pixels_src;
	if (SDL_MUSTLOCK(surface_dest))
		SDL_LockSurface(surface_dest);
	pixels_dest = (Uint32 *) surface_dest->pixels;
	pixels_src  = (Uint32 *) surface_src->pixels;
	for (int i = cmd->point.x; i < min(cmd->point.x + surface_src->w, surface_dest->w); i++) {
		for (int j = cmd->point.y; j < min(cmd->point.y + surface_src->h, surface_dest->h); j++)
			pixels_dest[j * surface_dest->w
			+ i] = pixels_src[(j - cmd->point.y) * surface_src->w + (i - cmd->point.x)];
	}
	if (SDL_MUSTLOCK(surface_dest))
		SDL_UnlockSurface(surface_dest);


	return 0;
} /* cimp_paste */

/**Une fonction qui copie la partie de l'image selectionnee et la remplace par du noir.
 * Renvoie 0 en cas de succes et -1 sinon. **/
int cimp_cut(t_cmd * cmd) {
	if (cimp_copy(cmd) < 0)
		return -1;

	SDL_Rect rect;
	if (cmd->rect.x != -1 && cmd->rect.y != -1 && cmd->rect.w != -1 && cmd->rect.h != -1) {
		rect = cmd->rect;
	}
	else {
		if (g_cimp->select == NULL) {
			printf("Pas de zone selectionnee : copie impossible \n");
			return -1;
		}
		rect = g_cimp->select->surface;
	}
	SDL_Surface * surface;
	surface = g_cimp->screen->buff_screen;
	Uint32 color = SDL_MapRGBA(surface->format, 0, 0, 0, 0);
	if (SDL_FillRect(surface, &rect, color) < 0)
		return -1;

	return 0;
}
