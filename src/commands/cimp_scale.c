#include "cimp.h"

t_rc_cmd cimp_scale(t_cmd * cmd) {
	SDL_Surface * source = g_cimp->screen[cmd->focus]->buff_screen;
	SDL_Surface * copy   = SDL_CreateRGBSurface(0, cmd->point.x,
			cmd->point.y, source->format->BitsPerPixel, source->format->Rmask,
			source->format->Gmask, source->format->Bmask, source->format->Amask);

	SDL_BlendMode oldBlendMode;

	SDL_GetSurfaceBlendMode(source, &oldBlendMode);

	SDL_SetSurfaceBlendMode(source, SDL_BLENDMODE_NONE);

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = cmd->point.x;
	rectangle.h = cmd->point.y;

	if (SDL_BlitScaled(source, NULL, copy, &rectangle) != 0) {
		SDL_FreeSurface(copy);
		SDL_SetSurfaceBlendMode(source, oldBlendMode);
		return (FAIL);
	}

	SDL_FreeSurface(source);
	g_cimp->screen[cmd->focus]->buff_screen = copy;
	SDL_SetSurfaceBlendMode(source, oldBlendMode);

	return (OK);
}
