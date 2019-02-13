#include "cimp.h"

void cimp_sym_verti(){
  if(g_cimp->screen->buff_screen){
    SDL_Surface *buff_screen=g_cimp->screen->buff_screen;
    if (SDL_MUSTLOCK(buff_screen))
      SDL_LockSurface(buff_screen);

    uint32_t *pixels = (uint32_t *)buff_screen->pixels;

    uint32_t tmp;
    printf("%d\n",buff_screen->w);
    for (int x = 0; x < buff_screen->w / 2; x++) {
      for (int y = 0; y < buff_screen->h; y++) {
		int A = (buff_screen->w * y) + x;
		int B = (buff_screen->w * y) + buff_screen->w - 1 - x;
        tmp = pixels[A];
        pixels[A] = pixels[B];
        pixels[B] = tmp;
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
    uint32_t tmp;
    for (int x = 0; x < buff_screen->w/2; x++) {
      for (int y = 0; y < buff_screen->h; y++) {
        tmp=pixels[x+(buff_screen->w*y)];
        pixels[x+(buff_screen->w*y)]=pixels[(y*buff_screen->w)+(buff_screen->w)-x];
        pixels[(y*buff_screen->w)+(buff_screen->w)-x]=tmp;
      }
    }
    if (SDL_MUSTLOCK(buff_screen))
      SDL_UnlockSurface(buff_screen);
  }
}
