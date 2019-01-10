
#ifndef ATPT_H
# define ATPT_H

# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_atpt
{
	struct termios	ios_old;
	struct termios	ios_actu;
}					t_atpt;

extern t_atpt		*g_atpt;

/*
**	src/loader.c
*/

int					atpt_init(void);
void				atpt_end(void);

/*
**	src/setup_termios.c
*/

int					setup_termios(void);
void				reset_termios(void);

/*
**	src/signal_handler.c
*/

void				init_signal_handlers(void);

#endif
