#include "cimp.h"

// Local to cimp_rotate.c
static void cimp_rotate90();

void cimp_rotate(int angle) {
	while (angle < 0)
		angle += 360;
	switch (angle % 360) {
		case 0:
			break;
		case 90:
			cimp_rotate90();
			break;
		case 180:
			cimp_sym_hori();
			cimp_sym_verti();
			break;
		case 270:
			cimp_rotate(180);
			cimp_rotate(90);
			break;
		default:
			printf("Nothing to do for now, invalid angle value, choose a multiple of 90°\n");
	}
}

static void cimp_rotate90() {
	int new_width;
	int new_height;

	SDL_GetWindowSize(g_cimp->screen->window, &new_height, &new_width);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, new_width, new_height, 32, 0, 0, 0, 0);
	uint32_t * old     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	uint32_t * new     = (uint32_t *) surf->pixels;
	for (int i = 0; i < new_height; i++) {
		for (int j = 0; j < new_width; j++) {
			new[new_width - 1 - j + i * new_width] = old[i + j * new_height];
		}
	}
	SDL_FreeSurface(g_cimp->screen->buff_screen);
	g_cimp->screen->buff_screen = surf;
	SDL_SetWindowSize(g_cimp->screen->window, new_width, new_height);
}
