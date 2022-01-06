/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/26 14:47:37 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_env	*ms_env;

	(void)argc;
	(void)argv;
	ms_env = init_ms_env(env);
	g_child_pid = 0;
	g_cmd_actu = 0;
	g_cmd_size_actu = 0;
	signal(SIGINT, handle_sigint);
	while (1)
	{
		ft_putstr("$> ");
		read_from_input();
		if (treat_cmd(g_cmd_actu, ms_env) == 1)
			break ;
	}
	free_ms_env(&ms_env);
	return (0);
}
