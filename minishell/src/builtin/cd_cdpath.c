/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:59:13 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/26 15:22:39 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		free_everything(char **str, char ***splited)
{
	int		index;
	
	ft_strdel(str);
	index = 0;
	while ((*splited)[index])
	{
		ft_strdel((*splited) + index);
		index++;
	}
	free((*splited));
	*splited = 0;
}

static char		*build_res(
					t_array_key **list_env,
					char *real_arg,
					char *cdpath_actu)
{
	struct stat		stats;
	char			*res;
	char			*tmp;

	res = 0;
	tmp = concat_dir_str(cdpath_actu, real_arg);
	if (lstat(tmp, &stats) != -1)
	{
		if (S_ISDIR(stats.st_mode))
		{
			res = normalize_path(list_env, tmp);
			ft_printf("%s\n", res);
		}
	}
	free(tmp);
	return (res);
}

char			*handle_cd_path(
					t_array_key **list_env,
					char *real_arg)
{
	char		*cdpath;
	char		**splited;
	char		*res;
	int			index;

	res = 0;
	if (*real_arg != '/' && ft_strncmp(real_arg, "~/", 2) != 0)
	{
		if ((cdpath = get_env_local(list_env, ENV_CDPATH)) != 0)
		{
			splited = ft_strsplit(cdpath, ':');
			index = -1;
			while (splited[++index])
			{
				if (ft_strcmp(splited[index], ".") == 0 || splited[index][0] != '/')
					continue ;
				if ((res = build_res(list_env, real_arg, splited[index])) != 0)
					break ;
			}
			free_everything(&cdpath, &splited);
			if (res != 0)
				return (res);
		}
	}
	return (normalize_path(list_env, real_arg));
}
