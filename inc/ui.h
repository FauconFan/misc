#ifndef UI_H
#define	UI_H

// Ncurses library
#include <curses.h>

#define	TIMEOUT_READ 100 // ms

typedef struct  s_ui{
	char *   pseudo;
	t_bool   with_ncurses;
	char     line[1024];
	size_t   len;
	t_list * li_messages;
	char *   buffer_in;
	int      fd_ui;
	int      fd_callback;
	int      fd_stop;
	int      fd_log;
	t_bool   has_received_stop;
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

int ui_getfd(void);
int ui_getcallbackfd(void);
void ui_receive(t_ui_in * in);
t_bool ui_setup(t_bool with_ncurses);
void ui_down(void);
t_bool ui_log_setup(int * fd);

void ui_main(t_bool with_ncurses, int fd_ui, int fd_callback, int fd_stop);
void ui_print(t_ui * ui);
char * ui_read_pseudo(void);

t_ui * ui_alloc(t_bool with_ncurses, int fd_ui, int fd_callback, int fd_stop);
void ui_free(t_ui * ui);
void ui_init_line(t_ui * ui);

t_bool  ui_stdin_custom_setup(int * fd_get, int * fd_stop);
int     ui_getstdin_custom(int fd_get);
void    ui_getstdin_stop(int fd_stop);
void    ui_getstdin_continue(int fd_stop);


#endif // ifndef UI_H
