#ifndef COMMANDS_H
#define	COMMANDS_H

int cimp_open(t_cmd * cmd);
int cimp_close(t_cmd * cmd);
int cimp_help(t_cmd * cmd);
int cimp_list(t_cmd * cmd);
int cimp_sym_verti(t_cmd * cmd);
int cimp_sym_hori(t_cmd * cmd);
int cimp_rotate(t_cmd * cmd);

#endif // ifndef COMMANDS_H
