#ifndef COMMANDS_H
#define	COMMANDS_H

// cimp_open.c:
int cimp_open(char * path, char ** errno_str);

// cimp_close.c:
int cimp_close();

// cimp_help.c:
void cimp_help();

// cimp_list.c:
void cimp_list();

// cimp_sym.c:
void cimp_sym_verti();
void cimp_sym_hori();

// cimp_rotate.c:
void cimp_rotate(int angle);


/* /!\ /!\ POSITION PROVISOIRE /!\/!\ */
void cimp_exe(t_parser_out * cmd);

#endif // ifndef COMMANDS_H
