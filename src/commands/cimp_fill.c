#include "cimp.h"

static uint32_t set_color(uint32_t unused, void * color) {
	(void) unused;
	return *((uint32_t *) color);
}

int cimp_fill(t_cmd * cmd) {
	if (g_cimp->screen) {
		SDL_Surface * buff_screen;
		SDL_Rect selection;
		uint32_t color;

		buff_screen = g_cimp->screen->buff_screen;
		selection   = sdl_surface_build_good_selection(buff_screen, cmd->rect);
		color       = SDL_MapRGB(buff_screen->format, cmd->color.r, cmd->color.g,
				cmd->color.b);

		sdl_surface_mapp(buff_screen, selection, set_color, &color);
	}
	return (0);
} /* cimp_fill */
