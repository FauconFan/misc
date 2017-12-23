/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/23 16:34:47 by fauconfan        ###   ########.fr       */
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
		if (treat_cmd(cmd, &(ms_env->env_local)) == 1)
			break ;
	}
	free_ms_env(&ms_env);
	return (0);
}
