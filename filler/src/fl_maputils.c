/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:59 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/08 08:05:22 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*interpret_line(char *line)
{
	char	*res;
	size_t	len;
	size_t	index;

	len = ft_strlen(line);
	res = ft_strnew(len);
	index = 0;
	while (index < len)
	{
		res[index] = EMPTY_CASE;
		if (line[index] == O_MAJ_CASE || line[index] == O_MIN_CASE)
			res[index] = O_CASE;
		else if (line[index] == X_MAJ_CASE || line[index] == X_MIN_CASE)
			res[index] = X_CASE;
		index++;
	}
	if (res[index - 1] == '\n')
		res[index - 1] = '\0';
	return (res);
}

void			load_map(t_fillerenv *fl_env)
{
	char	*line;
	char	**splited;

	get_next_line(0, &line, fl_env->env_gnl);
	splited = ft_strsplit(line, ' ');
	free_map(fl_env);
	load_new_map(fl_env, ft_atoi(splited[2]), ft_atoi(splited[1]));
	free(line);
	free(splited[0]);
	free(splited[1]);
	free(splited[2]);
	free(splited);
}

void			load_new_map(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	char			**res;
	char			*tmp;
	size_t			index;
	int				ret;

	ft_memcheck((res = (char **)malloc(sizeof(char *) * (size_y))));
	index = 0;
	get_next_line(0, res, fl_env->env_gnl);
	free(*res);
	tmp = ft_strnew(size_x + 4 + 1);
	while (index < size_y)
	{
		if ((ret = read(0, tmp, size_x + 4 + 1)) == -1)
			ft_die(strerror(errno));
		res[index] = interpret_line(tmp + 4);
		index++;
	}
	free(tmp);
	fl_env->map = res;
	fl_env->size_x = size_x;
	fl_env->size_y = size_y;
}

void			free_map(t_fillerenv *fl_env)
{
	size_t		index;

	if (fl_env->size_x != 0 && fl_env->size_y != 0 &&
		fl_env->map != NULL)
	{
		index = 0;
		while (index < fl_env->size_y)
		{
			free(fl_env->map[index]);
			index++;
		}
		free(fl_env->map);
	}
}

void			print_map(t_fillerenv *fl_env)
{
	size_t	index;

	if (fl_env->map != NULL)
	{
		index = 0;
		while (index < fl_env->size_y)
		{
			ft_dprintf(2, "%s\n", fl_env->map[index]);
			index++;
		}
	}
}
