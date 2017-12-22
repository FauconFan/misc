/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:15:30 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 14:56:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		real_cd(char **curpath, t_array_key **list_env, char **args)
{
	if (*args == 0)
	{
		*curpath = get_env_local(list_env, ENV_CST_HOME);
		if (*curpath == 0)
		{
			ft_dprintf(2, "cd: %s not set\n", ENV_CST_HOME);
			return (1);
		}
	}
	else if ((*args)[0] == '-' && (*args)[1] == 0)
	{
		*curpath = get_env_local(list_env, ENV_CST_OLDPWD);
		if (*curpath == 0)
		{
			ft_dprintf(2, "cd: %s not set\n", ENV_CST_OLDPWD);
			return (1);
		}
	}
	else
		*curpath = ft_strdup(*args);
	return (0);
}

void			builtin_cd(t_array_key ***list_env, char **args)
{
	char	*cwd;
	char	*curpath;
	int		size;

	size = 0;
	while (args[size])
		size++;
	if (size >= 2)
	{
		ft_dprintf(2, "cd: Too many arguments\n");
		return ;
	}
	curpath = 0;
	if (real_cd(&curpath, *list_env, args) == 0)
	{
		cwd = getwd(0);
		if (chdir(curpath) == -1)
			ft_dprintf(2, "%s is unreachable\n", curpath);
		else
		{
			set_env_local(list_env, ENV_CST_OLDPWD, cwd);
			free(cwd);
			cwd = getwd(0);
			set_env_local(list_env, ENV_CST_PWD, cwd);
		}
		free(cwd);
		free(curpath);
	}
}
