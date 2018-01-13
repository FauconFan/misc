/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:22 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 15:32:53 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		setup(t_select **env, int argc, char **argv)
{
	*env = init_select(argc, argv);
	setup_termios(*env);
}

static void		ft_select(t_select *env)
{
	char		c;

	while (1)
	{
		display_column(env);
		read(0, &c, 1);
		if (c == '\n')
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_select	*env;

	setup(&env, argc - 1, argv + 1);
	ft_select(env);
	reset_termios(env);
	free_select(&env);
	return (0);
}
