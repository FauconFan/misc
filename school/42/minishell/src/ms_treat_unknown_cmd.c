/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_treat_unknown_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:15:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/23 10:24:42 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			treat_if_path_is_defined(
						t_array_key **env_local,
						char *cmd_real,
						char **args,
						char *path_variable)
{
	char	**parsed;
	t_bool	is_found;
	int		index;

	parsed = ft_strsplit(path_variable, ':');
	index = 0;
	is_found = FALSE;
	while (parsed[index])
	{
		is_found = is_file_exist(parsed[index], cmd_real);
		if (is_found)
			break ;
		index++;
	}
	if (is_found)
	{
		fork_n_wait(env_local, parsed[index], cmd_real, args);
	}
	index = -1;
	while (parsed[++index])
		free(parsed[index]);
	free(parsed);
	if (is_found == FALSE)
		return (1);
	return (0);
}

void				treat_from_scratch(
						t_array_key **env_local,
						char *cmd_real,
						char **args)
{
	char	*path_variable;

	path_variable = get_env_local(env_local, "PATH");
	if (path_variable == 0 ||
			treat_if_path_is_defined(env_local, cmd_real, args, path_variable))
		ft_dprintf(2, "%s: %s\n", cmd_real, CST_CMD_NOT_FOUND);
	free(path_variable);
}
