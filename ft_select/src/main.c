/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:22 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/11 16:26:52 by fauconfan        ###   ########.fr       */
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
	if (isatty(STDOUT_FILENO) == 0 || isatty(STDERR_FILENO) == 0)
	{
		ft_die("Not running in a terminal");
	}
	ft_putendl(tty_name);
	if ((res = tgetent(0, tty_name)) < 1)
	{
		if (res == -1)
			ft_die("Terminfo database not found.");
		else
			ft_die("No such entry in the terminfo database.");
	}
}

int				main(void)
{
	check_conditions();
	return (0);
}
