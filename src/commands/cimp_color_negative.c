#include "cimp.h"

static uint32_t to_negative(uint32_t col, void * format_pixel) {
	uint8_t r, g, b;
	SDL_PixelFormat * format;

	format = (SDL_PixelFormat *) format_pixel;
	SDL_GetRGB(col, format, &r, &g, &b);
	return SDL_MapRGB(format, 255 - r, 255 - g, 255 - b);
}

int cimp_color_negative(t_cmd * cmd) {
	if (g_cimp->screen) {
		SDL_Surface * buff_screen;
		SDL_Rect selection;

		buff_screen = g_cimp->screen->buff_screen;
		selection   = sdl_surface_build_good_selection(buff_screen, cmd->rect);

		sdl_surface_mapp(buff_screen, selection, to_negative, buff_screen->format);
	}
	return (0);
} /* cimp_fill */
