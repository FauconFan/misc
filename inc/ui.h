#ifndef UI_H
#define	UI_H

#include <curses.h>
#include <ctype.h>
#include <math.h>

typedef struct  s_ui{
	char *   pseudo;
	char     line[1024];
	size_t   len;
	t_list * li_messages;
	char     buffer_in[1024];
}               t_ui;

typedef enum e_ui_type{
	UI_OK,
	UI_STOP,
	UI_MESSAGE,
}            t_ui_type;

typedef struct  s_ui_in{
	t_ui_type type;
	union {
		t_bool ok;
		char * message;
	} u;
}               t_ui_in;

int     ui_getfd(void);
int     ui_getcallbackfd(void);
void	ui_receive(t_ui_in * in);
void    ui_setup(void);
void    ui_down(void);

void    ui_main(int fd_ui, int fd_callback, int fd_stop);
void    ui_print(t_ui * ui);
char * ui_read_pseudo(void);

t_ui * ui_alloc(char * pseudo);
void    ui_free(t_ui * ui);
void    ui_init_line(t_ui * ui);
void    ui_treat_buffer(t_ui * ui);

#endif // ifndef UI_H
