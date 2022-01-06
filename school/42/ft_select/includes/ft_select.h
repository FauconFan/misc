/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:34 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/16 12:05:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "libft.h"

# define C_COLOR				"\033[35m"
# define O_COLOR				"\033[36m"
# define H_COLOR				"\033[34m"
# define MAKEFILE_COLOR			"\033[33m"
# define A_COLOR				"\033[31m"

# define DEFAULT_COLOR			"\033[0m"
# define REVERSE_VIDEO_COLOR	"\033[7m"
# define UNDERLINED				"\033[4m"

# define LEFT_KEY				4479771
# define UP_KEY					4283163
# define RIGHT_KEY				4414235
# define DOWN_KEY				4348699

# define ESC_KEY				27

# define BSP_KEY				127
# define DEL_KEY				2117294875L

typedef struct		s_arg
{
	char				*value;
	t_bool				is_selected;
}					t_arg;

typedef struct		s_select
{
	t_arg				**args;
	int					tot_args;
	int					index_selected;
	struct winsize		ws;
	struct termios		ios_old;
	struct termios		ios_actu;
	int					rows;
	int					cols;
}					t_select;

t_select			*g_select;

/*
**	Init Select
*/

void				free_select(t_select **sel);
void				delete_arg(t_select *env);
t_select			*init_select(int size, char **argv);
void				display_selected(t_select *env);

/*
**	Display column
*/

void				display_column();

/*
**	Termios utils
*/

int					ft_printnbr(int c);
void				setup_termios();
void				reset_termios();

/*
**	Move Utils
*/

t_bool				move(long c, t_select *env);

/*
**	Signal Handling
*/

void				signal_handler(int signo);
void				handle_sigstop();
void				handle_sigcont();
void				stop_program();
void				init_signal_handlers(void);

#endif
