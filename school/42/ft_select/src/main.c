/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:45:22 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 21:50:53 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_printusage(void)
{
	ft_putstr_fd("Usage ./ft_select [List args]\n", STDERR_FILENO);
}

static void		setup(t_select **env, int argc, char **argv)
{
	*env = init_select(argc, argv);
	setup_termios();
}

static void		ft_select(t_select *env)
{
	long		c;

	while (1)
	{
		display_column();
		c = 0;
		read(STDIN_FILENO, &c, 8);
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
			else if (c == ESC_KEY)
				stop_program();
			else if (c == BSP_KEY || c == DEL_KEY)
				delete_arg(env);
		}
	}
}

int				main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printusage();
		return (0);
	}
	setup(&g_select, argc - 1, argv + 1);
	init_signal_handlers();
	ft_select(g_select);
	reset_termios();
	display_selected(g_select);
	free_select(&g_select);
	return (0);
}
