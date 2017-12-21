/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:12:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 19:20:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		fork_n_wait(t_ms_env *ms_env, char *directory, char *cmd_real, char **args)
{
	int		status;
	char	*full_path_exe;

	full_path_exe = concat_dir_str(directory, cmd_real);
	if (fork() == 0)
	{
		ft_printf("debug :%s\n", *args);
		execve(full_path_exe, args, ms_env->cpy_env);
	}
	else
	{
		wait(&status);
	}
	free(full_path_exe);
}