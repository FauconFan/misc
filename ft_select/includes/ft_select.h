/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:34 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 15:32:23 by fauconfan        ###   ########.fr       */
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

typedef struct		s_arg
{
	char		*value;
	t_bool		is_selected;
}					t_arg;

typedef struct		s_select
{
	t_arg			**args;
	int				width_screen;
	int				tot_args;
	struct termios	ios_old;
	struct termios	ios_actu;
}					t_select;

/*
**	Init Select
*/

void				free_select(t_select **sel);
t_select			*init_select(int size, char **argv);

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

#endif