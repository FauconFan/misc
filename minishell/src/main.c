/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/25 09:08:36 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_env	*ms_env;
	char		*cmd;

	(void)argc;
	(void)argv;
	ms_env = init_ms_env(env);
	while (1)
	{
		ft_putstr("$> ");
		cmd = read_from_input();
		if (treat_cmd(cmd, ms_env) == 1)
			break ;
	}
	free_ms_env(&ms_env);
	return (0);
}
