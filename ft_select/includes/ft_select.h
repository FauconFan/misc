/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:34 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 17:35:52 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "libft.h"

# define DEFAULT_COLOR			"\033[0m"
# define REVERSE_VIDEO_COLOR	"\033[7m"
# define UNDERLINED				"\033[4m"

# define LEFT_KEY				4479771
# define UP_KEY					4283163
# define RIGHT_KEY				4414235
# define DOWN_KEY				4348699

typedef struct		s_arg
{
	char		*value;
	t_bool		is_selected;
}					t_arg;

typedef struct		s_select
{
	t_arg			**args;
	int				tot_args;
	int				index_selected;
	struct winsize	ws;
	struct termios	ios_old;
	struct termios	ios_actu;
	int				rows;
	int				cols;
}					t_select;

/*
**	Init Select
*/

void				free_select(t_select **sel);
t_select			*init_select(int size, char **argv);
void				display_selected(t_select *env);

/*
**	Display column
*/

void				display_column(t_select *env);

/*
**	Termios utils
*/

int					ft_printnbr(int c);
void				setup_termios(t_select *env);
void				reset_termios(t_select *env);

/*
**	Move Utils
*/

t_bool				move(long c, t_select *env);

#endif