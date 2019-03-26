#include "cimp.h"

SDL_Rect    sdl_surface_build_good_selection(SDL_Surface * surf, SDL_Rect param) {
	SDL_Rect res;

	if (param.x != -1) { // isset
		res = param;
	}
	else if (g_cimp->select != NULL) {
		res = g_cimp->select->surface;
	}
	else {
		res.x = 0;
		res.y = 0;
		res.w = surf->w;
		res.h = surf->h;
	}
	return (res);
}

// void        sdl_surface_map(SDL_Surface * surf, SDL_Rect rect, uint32_t (* fp)(uint32_t)) {
//  if (SDL_MUSTLOCK(surf))
//      SDL_LockSurface(surf);

//  uint32_t * pixels = (uint32_t *) surf->pixels;

//  for (int i = rect.x; i < rect.x + rect.w; ++i) {
//      for (int j = rect.y; j < rect.y + rect.h; ++j) {
//          pixels[j * surf->w + i] = fp(pixels[j * surf->w + i]);
//      }
//  }

//  if (SDL_MUSTLOCK(surf))
//      SDL_UnlockSurface(surf);
// }

void        sdl_surface_mapp(SDL_Surface * surf, SDL_Rect rect,
  uint32_t (* fp)(uint32_t, void *), void * v) {
	if (SDL_MUSTLOCK(surf))
		SDL_LockSurface(surf);

	uint32_t * pixels = (uint32_t *) surf->pixels;

	for (int i = rect.x; i < rect.x + rect.w; ++i) {
		for (int j = rect.y; j < rect.y + rect.h; ++j) {
			pixels[j * surf->w + i] = fp(pixels[j * surf->w + i], v);
		}
	}

	if (SDL_MUSTLOCK(surf))
		SDL_UnlockSurface(surf);
}
