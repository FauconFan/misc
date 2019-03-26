#include "cimp.h"

int cimp_fill(t_cmd * cmd) {
	if (g_cimp->screen) {
		SDL_Surface * buff_screen = g_cimp->screen->buff_screen;

		int i_min = 0;
		int j_min = 0;
		int i_max = buff_screen->w;
		int j_max = buff_screen->h;

		if (cmd->rect.x != -1) {
			i_min = cmd->rect.x;
			j_min = cmd->rect.y;
			i_max = cmd->rect.w + i_min;
			j_max = cmd->rect.h + j_min;
		}
		else if (g_cimp->select != NULL) {
			i_min = g_cimp->select->surface.x;
			j_min = g_cimp->select->surface.y;
			i_max = g_cimp->select->surface.w + i_min;
			j_max = g_cimp->select->surface.h + j_min;
		}

		if (SDL_MUSTLOCK(buff_screen))
			SDL_LockSurface(buff_screen);

		uint32_t * pixels = (uint32_t *) buff_screen->pixels;
		uint32_t color    = SDL_MapRGB(buff_screen->format, cmd->color[0].r, cmd->color[0].g,
				cmd->color[0].b);

		for (int i = i_min; i < i_max; ++i) {
			for (int j = j_min; j < j_max; ++j) {
				pixels[j * buff_screen->w + i] = color;
			}
		}

		if (SDL_MUSTLOCK(buff_screen))
			SDL_UnlockSurface(buff_screen);
	}
	return (0);
} /* cimp_fill */
