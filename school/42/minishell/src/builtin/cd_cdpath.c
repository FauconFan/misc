/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:59:13 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/28 10:12:42 by jpriou           ###   ########.fr       */
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
					char *re_arg)
{
	char		*cdpath;
	char		**spl;
	char		*res;
	int			index;

	res = 0;
	if (*re_arg != '/' && ft_strncmp(re_arg, "~/", 2) != 0 && *re_arg != '.')
	{
		if ((cdpath = get_env_local(list_env, ENV_CDPATH)) != 0)
		{
			spl = ft_strsplit(cdpath, ':');
			index = -1;
			while (spl[++index])
			{
				if (ft_strcmp(spl[index], ".") == 0 || spl[index][0] != '/')
					continue ;
				if ((res = build_res(list_env, re_arg, spl[index])) != 0)
					break ;
			}
			free_everything(&cdpath, &spl);
			if (res != 0)
				return (res);
		}
	}
	return (normalize_path(list_env, re_arg));
}
