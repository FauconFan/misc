/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_treat_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:51:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 18:15:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool		look_in_this_directory(char *directory, char *search_binary)
{
	DIR				*dir_actu;
	struct dirent	*dirent_actu;
	t_bool			res;

	res = FALSE;
	if ((dir_actu = opendir(directory)) == 0)
		return (FALSE);
	while ((dirent_actu = readdir(dir_actu)))
	{
		if (ft_strcmp(dirent_actu->d_name, search_binary) == 0)
		{
			res = TRUE;
			break ;
		}
	}
	if (closedir(dir_actu) == -1)
		return (FALSE);
	return (res);
}

static int			treat_if_path_is_defined(t_ms_env *ms_env, char *cmd_real, char **args, char *path_variable)
{
	char	**parsed;
	t_bool	is_found;
	int		index;

	parsed = ft_strsplit(path_variable, ':');
	index = 0;
	is_found = FALSE;
	while (parsed[index])
	{
		is_found = look_in_this_directory(parsed[index], cmd_real);
		if (is_found)
			break ;
		index++;
	}
	if (is_found)
	{
		fork_n_wait(ms_env, parsed[index], cmd_real, args);
	}
	index = -1;
	while (parsed[++index])
		free(parsed[index]);
	free(parsed);
	if (is_found == FALSE)
		return (1);
	return (0);
}

void				treat_from_scratch(t_ms_env *ms_env, char *cmd_real, char **args)
{
	char	*path_variable;

	path_variable = get_env_local(ms_env->cpy_env, "PATH");
	if (path_variable == 0 || treat_if_path_is_defined(ms_env, cmd_real, args, path_variable) != 0)
		ft_dprintf(2, "%s: %s\n", cmd_real, CST_CMD_NOT_FOUND);
	free(path_variable);
}
