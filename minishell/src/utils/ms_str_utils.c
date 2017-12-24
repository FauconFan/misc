/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:56:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/24 10:25:13 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		normalize_absolute_path(char *res)
{
	int		size;
	int		index;

	size = 1;
	while (res[size] != 0 && (res[size] != '/' || size++))
	{
		if (ft_strncmp(res + size, "../", 3) == 0)
		{
			size--;
			index = 4;
			while (--size >= 0 && res[size] != '/')
				index++;
			if (size < 0)
				return (1);
			ft_strncpy(res + size, res + size + index,
						ft_strlen(res + size + index) + 1);
		}
		else if (ft_strncmp(res + size, "./", 2) == 0)
			ft_strncpy(res + size, res + size + 2,
							ft_strlen(res + size + 2) + 1);
		else
			while (res[size] != '/' && res[size] != 0)
				size++;
	}
	return (0);
}

char			*normalize_path(t_array_key **env_actu, char *curpath)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	if (ft_strncmp(curpath, "~/", 2) == 0)
	{
		tmp2 = get_env_local(env_actu, ENV_CST_HOME);
		tmp = concat_dir_str(tmp2, curpath + 2);
		free(tmp2);
	}
	else if (*curpath != '/')
	{
		tmp2 = get_env_local(env_actu, ENV_CST_PWD);
		tmp = concat_dir_str(tmp2, curpath);
		free(tmp2);
	}
	else
		tmp = ft_strdup(curpath);
	res = concat_dir_str(tmp, "");
	free(tmp);
	normalize_absolute_path(res);
	return (res);
}

char			*concat_dir_str(char *s1, char *s2)
{
	char	*res;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (s1[l1 - 1] == '/')
	{
		res = ft_strnew(l1 + l2);
		ft_strncpy(res, s1, l1);
		ft_strncpy(res + l1, s2, l2);
	}
	else
	{
		res = ft_strnew(l1 + l2 + 1);
		ft_strncpy(res, s1, l1);
		res[l1] = '/';
		ft_strncpy(res + l1 + 1, s2, l2);
	}
	return (res);
}

char			*ft_strreplace_free_first(char *res, char *search, char *rep)
{
	char	*tmp;
	int		pos;

	if ((pos = ft_strpos(res, search)) == -1)
	{
		tmp = ft_strdup(res);
		free(res);
		return (tmp);
	}
	tmp = ft_strnew(pos + ft_strlen(rep) + ft_strlen(res + pos + ft_strlen(search)));
	ft_strncpy(tmp, res, pos);
	ft_strcpy(tmp + pos, rep);
	ft_strcpy(tmp + pos + ft_strlen(rep), res + pos + ft_strlen(search));
	free(res);
	return (ft_strreplace_free_first(tmp, search, rep));
}
