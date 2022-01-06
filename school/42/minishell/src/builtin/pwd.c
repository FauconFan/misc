/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:23:14 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/25 09:48:31 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		treat_args(char **args, t_bool *logical_pwd)
{
	int		index;

	*logical_pwd = TRUE;
	while (*args)
	{
		index = 0;
		if (**args != '-')
			return (1);
		while ((*args)[++index])
		{
			if ((*args)[index] == 'L')
				*logical_pwd = TRUE;
			else if ((*args)[index] == 'P')
				*logical_pwd = FALSE;
			else
				return (1);
		}
		args++;
	}
	return (0);
}

void			builtin_pwd(t_array_key ***env_global, char **args)
{
	t_bool	logical_pwd;
	char	*path;

	if (treat_args(args, &logical_pwd) == 1)
		display_usage(CST_PWD);
	else if (logical_pwd)
	{
		path = get_env_local(*env_global, ENV_CST_PWD);
		if (path == 0)
			ft_dprintf(2, "Variable PWD is not defined\n");
		else
		{
			ft_printf("%s\n", path);
			free(path);
		}
	}
	else
	{
		path = get_abs_path_from_getcwd();
		ft_printf("%s\n", path);
		free(path);
	}
}
