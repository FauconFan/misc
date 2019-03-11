#ifndef ENV_H
#define	ENV_H

// t_cimp.c

int             cimp_init();
void            cimp_end();

// t_cimp_screen.c

t_cimp_screen * cimp_init_screen(
  char *  path_bmp,
  char ** errno_str);
void                cimp_end_screen(t_cimp_screen * sc);
void                cimp_update_screen(t_cimp_screen * screen);

// t_cimp_select.c
t_cimp_select * cimp_init_select (SDL_Rect rectangle, char ** errno_str);
void cimp_end_select (t_cimp_select * selection);

#endif // ifndef ENV_H
