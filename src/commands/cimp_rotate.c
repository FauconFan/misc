#include "cimp.h"

// Local to cimp_rotate.c
static void real_rotate(t_cmd * cmd, int angle);
static void real_rotate90();

int cimp_rotate(t_cmd * cmd) {
	if (cmd != NULL && g_cimp && g_cimp->screen && g_cimp->screen->buff_screen) {
		real_rotate(cmd, cmd->angle);
		return (0);
	}
	return 1;
}

static void real_rotate(t_cmd * cmd, int angle) {
	while (angle < 0)
		angle += 360;
	switch (angle % 360) {
		case 0:
			break;
		case 90:
			real_rotate90();
			break;
		case 180:
			cimp_sym_hori(cmd);
			cimp_sym_verti(cmd);
			break;
		case 270:
			real_rotate(cmd, 180);
			real_rotate(cmd, 90);
			break;
		default:
			printf("Nothing to do for now, invalid angle value, choose a multiple of 90°\n");
	}
}

static void real_rotate90() {
	int new_width  = g_cimp->screen->buff_screen->h;
	int new_height = g_cimp->screen->buff_screen->w;

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
	if (g_cimp->screen->window) {
		SDL_SetWindowSize(g_cimp->screen->window, new_width, new_height);
	}
}
