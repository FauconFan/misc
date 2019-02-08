#include "cimp.h"

void cimp_sym_verti(){
  if(g_cimp->screen->buff_screen){
    SDL_Surface *buff_screen=g_cimp->screen->buff_screen;
    if (SDL_MUSTLOCK(buff_screen))
      SDL_LockSurface(buff_screen);

    uint32_t *pixels = (uint32_t *)buff_screen->pixels;
    for (int x = 0; x < buff_screen->w/2; x++) {
      for (int y = 0; y < buff_screen->h; y++) {
        pixels[x + (y * buff_screen->w)] = pixels[buff_screen->w - x + (y * buff_screen->w)];
      }
    }

    if (SDL_MUSTLOCK(buff_screen))
      SDL_UnlockSurface(buff_screen);
  }
}

void cimp_sym_hori(){
  if(g_cimp->screen->buff_screen){
    SDL_Surface *buff_screen=g_cimp->screen->buff_screen;
    if (SDL_MUSTLOCK(buff_screen))
      SDL_LockSurface(buff_screen);

    uint32_t *pixels = (uint32_t *)buff_screen->pixels;

    for (int x = 0; x < buff_screen->w; x++) {
      for (int y = 0; y < buff_screen->h; y++) {
        pixels[x + (y * buff_screen->w)] = SDL_MapRGB(buff_screen->format, 0, 0, 0xFF);
      }
    }
    if (SDL_MUSTLOCK(buff_screen))
      SDL_UnlockSurface(buff_screen);
  }
}
