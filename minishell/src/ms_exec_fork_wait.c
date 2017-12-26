/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:12:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/26 14:36:18 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**build_args_for_fork(char *full_path_exe, char **args)
{
	char	**res;
	int		index;

	index = 0;
	while (args[index])
		index++;
	ft_memcheck((res = (char **)malloc(sizeof(char *) * (index + 2))));
	res[0] = full_path_exe;
	index = 1;
	while (args[index - 1])
	{
		res[index] = args[index - 1];
		index++;
	}
	res[index] = 0;
	return (res);
}

void		fork_n_wait(
				t_array_key **env_actu,
				char *directory,
				char *cmd_real,
				char **args)
{
	int		status;
	char	*full_path_exe;
	char	**argstmp;
	char	**env_tmp;

	full_path_exe = concat_dir_str(directory, cmd_real);
	argstmp = build_args_for_fork(full_path_exe, args);
	env_tmp = from_array_keys_to_array_string(env_actu);
	if ((g_child_pid = fork()) == 0)
	{
		execve(full_path_exe, argstmp, env_tmp);
	}
	else
	{ 
		wait(&status);
	}
	g_child_pid = 0;
	free_array_string(env_tmp);
	free(full_path_exe);
	free(argstmp);
}
