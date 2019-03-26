#ifndef COMMANDS_H
#define	COMMANDS_H

int cimp_open(t_cmd * cmd);
int cimp_close(t_cmd * cmd);
int cimp_help(t_cmd * cmd);
int cimp_list(t_cmd * cmd);
int cimp_sym_verti(t_cmd * cmd);
int cimp_sym_hori(t_cmd * cmd);
int cimp_rotate(t_cmd * cmd);
int cimp_select(t_cmd * cmd);
int cimp_unselect(t_cmd * cmd);
int cimp_save(t_cmd * cmd);
int cimp_update(t_cmd * cmd);
int cimp_fill(t_cmd * cmd);
int cimp_color_negative(t_cmd * cmd);
int cimp_color_gray(t_cmd * cmd);
int cimp_color_replace(t_cmd * cmd);

#endif // ifndef COMMANDS_H
