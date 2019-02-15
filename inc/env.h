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

#endif // ifndef ENV_H
