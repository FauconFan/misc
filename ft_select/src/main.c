/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:22 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 17:33:22 by fauconfan        ###   ########.fr       */
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
	long		c;

	while (1)
	{
		display_column(env);
		ft_dprintf(STDERR_FILENO, "index %d\n", env->index_selected);
		c = 0;
		read(STDERR_FILENO, &c, 8);
		if (c == '\n')
			break ;
		else if (move(c, env) == FALSE)
		{
			if (c == ' ')
			{
				env->args[env->index_selected]->is_selected =
					(env->args[env->index_selected]->is_selected == FALSE);
				move(RIGHT_KEY, env);
			}
		}
	}
}

int				main(int argc, char **argv)
{
	t_select	*env;

	setup(&env, argc - 1, argv + 1);
	ft_select(env);
	reset_termios(env);
	display_selected(env);
	free_select(&env);
	return (0);
}
