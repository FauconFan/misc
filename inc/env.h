#ifndef ENV_H
#define	ENV_H

// t_cimp.c
int             cimp_init();
void            cimp_end();

// t_cimp_screen.c
t_cimp_screen * cimp_init_screen(char * path_bmp);
void cimp_end_screen(t_cimp_screen * sc);
void cimp_update_screen(t_cimp_screen * screen);

// t_cimp_select.c
t_cimp_select * cimp_init_select(SDL_Rect rectangle);
void cimp_end_select(t_cimp_select * selection);

// t_cimp_event.c
t_cimp_event * init_cimp_event();
void free_cimp_event(t_cimp_event * evnmt);
void update_event(t_cimp_event * evnmt);

// t_cmd.c
t_cmd * cmd_alloc();
void cmd_free(t_cmd * cmd);

// t_arg_type.c
const char * arg_type_to_string(t_arg_type atype);

#endif // ifndef ENV_H
