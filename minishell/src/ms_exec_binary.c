/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 11:03:41 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/24 11:11:27 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		is_binary(char *real_cmd)
{
	struct stat		stats;

	if (ft_strcpos(real_cmd, '/') == -1)
		return (FALSE);
	if (lstat(real_cmd, &stats) == -1)
		return (FALSE);
	return (S_ISREG(stats.st_mode) && stats.st_mode & S_IXUSR);
}

void		treat_with_binary(
				t_array_key **env_local,
				char *real_cmd,
				char **args)
{
	fork_n_wait(env_local, 0, real_cmd, args);
}
