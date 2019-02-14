#include "cimp.h"
void cimp_rotate90();
int max(int a, int b);
void cimp_rotate(int angle){
  while(angle<0)
    angle+=360;
  switch (angle%360) {
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
void cimp_rotate90(){

  int new_width;
  int new_height;
  SDL_GetWindowSize(g_cimp->screen->window,&new_height,&new_width);
  SDL_SetWindowSize(g_cimp->screen->window,new_height,new_width);
}
