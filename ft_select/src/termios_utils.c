/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:28:19 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 18:36:05 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		check_conditions(void)
{
	char	*tty_name;
	int		res;

	tty_name = getenv("TERM");
	if (tty_name == NULL)
	{
		ft_die("Variable Term not set.");
	}
	if (isatty(STDERR_FILENO) == 0 || isatty(STDIN_FILENO) == 0)
	{
		ft_die("Not running in a terminal");
	}
	if ((res = tgetent(0, tty_name)) < 1)
	{
		if (res == -1)
			ft_die("Terminfo database not found.");
		else
			ft_die("No such entry in the terminfo database.");
	}
}

int				ft_printnbr(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

void			setup_termios()
{
	check_conditions();
	tcgetattr(STDERR_FILENO, &g_select->ios_old);
	tcgetattr(STDERR_FILENO, &g_select->ios_actu);
	g_select->ios_actu.c_lflag &= ~ICANON;
	g_select->ios_actu.c_cc[VMIN] = 1;
	g_select->ios_actu.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &g_select->ios_actu);
	tputs(tgetstr("ti", NULL), 1, ft_printnbr);
	tputs(tgetstr("vi", NULL), 1, ft_printnbr);
}

void			reset_termios()
{	
	tcsetattr(STDERR_FILENO, TCSANOW, &g_select->ios_old);
	tputs(tgetstr("ve", NULL), 1, ft_printnbr);
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
}
