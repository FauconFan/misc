#include "libtest.h"

t_bool compareSurfaces(SDL_Surface * surf1, SDL_Surface * surf2) {
	if (surf1 == NULL || surf2 == NULL)
		return (FALSE);

	if (surf1->w != surf2->w || surf1->h != surf2->h)
		return (FALSE);

	uint32_t * surf1_pixels = (uint32_t *) surf1->pixels;
	uint32_t * surf2_pixels = (uint32_t *) surf2->pixels;
	for (int i = 0; i < surf2->w * surf2->h; i++) {
		if (surf1_pixels[i] != surf2_pixels[i])
			return (FALSE);
	}
	return (TRUE);
}
