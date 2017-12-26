/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:15:30 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/25 20:14:50 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		handle_exception(
					char **curpath,
					t_array_key **list_env,
					char *real_args)
{
	if (real_args == 0)
	{
		*curpath = get_env_local(list_env, ENV_CST_HOME);
		if (*curpath == 0)
		{
			ft_dprintf(2, "cd: %s not set\n", ENV_CST_HOME);
			return (1);
		}
	}
	else if ((real_args)[0] == '-' && (real_args)[1] == 0)
	{
		*curpath = get_env_local(list_env, ENV_CST_OLDPWD);
		if (*curpath == 0)
		{
			ft_dprintf(2, "cd: %s not set\n", ENV_CST_OLDPWD);
			return (1);
		}
	}
	else
		*curpath = normalize_path(list_env, real_args);
	return (0);
}

static void		real_cd(
					char *curpath,
					t_array_key ***list_env,
					char *real_arg,
					t_bool logical_cd)
{
	char	*cwd;
	char	*tmp;

	cwd = get_env_local(*list_env, ENV_CST_PWD);
	if (chdir(curpath) == -1)
	{
		if ((tmp = why_a_folder_is_unreachable(curpath)))
			ft_dprintf(2, "cd: %s: %s\n", tmp, real_arg);
		else
			ft_dprintf(2, "cd: %s\n", real_arg);
	}
	else
	{
		set_env_local(list_env, ENV_CST_OLDPWD, cwd);
		if (logical_cd)
			set_env_local(list_env, ENV_CST_PWD, curpath);
		else
		{
			tmp = get_abs_path_from_getcwd();
			set_env_local(list_env, ENV_CST_PWD, tmp);
			free(tmp);
		}
	}
	free(cwd);
}

static int		parse_arg(
					char **args,
					char **real_arg,
					t_bool *logical_cd,
					int size)
{
	int		index[2];

	index[0] = -1;
	while (++index[0] < size)
	{
		if (args[index[0]][0] == '-' && args[index[0]][1] != 0 &&
										args[index[0]][1] != '-')
		{
			index[1] = 0;
			while (args[index[0]][++index[1]])
			{
				if (args[index[0]][index[1]] != 'P' &&
							args[index[0]][index[1]] != 'L')
					return (1);
				*logical_cd = (args[index[0]][index[1]] == 'L');
			}
		}
		else if (ft_strcmp(args[index[0]], "--") != 0 || ++index[0])
			break ;
	}
	if (index[0] == size - 1 || index[0] == size)
		*real_arg = args[index[0]];
	else
		return (1);
	return (0);
}

void			builtin_cd(t_array_key ***list_env, char **args)
{
	char	*curpath;
	char	*real_arg;
	int		size;
	t_bool	logical_cd;

	size = 0;
	while (args[size])
		size++;
	logical_cd = TRUE;
	real_arg = 0;
	if (parse_arg(args, &real_arg, &logical_cd, size))
	{
		display_usage(CST_CD);
		return ;
	}
	if (handle_exception(&curpath, *list_env, real_arg) == 0)
		real_cd(curpath, list_env, real_arg, logical_cd);
	free(curpath);
}
