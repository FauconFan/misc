/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:59 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/11 00:10:47 by fauconfan        ###   ########.fr       */
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
	int		x;
	int		y;

	get_next_line(0, &line, fl_env->env_gnl);
	if (fl_verify_loader_map(line) == FALSE)
	{
		free(line);
		free_env(&fl_env, WRONG_FORMAT);
	}
	splited = ft_strsplit(line, ' ');
	free_map(fl_env);
	x = ft_atoi(splited[2]);
	y = ft_atoi(splited[1]);
	fl_free_parsed_string(&splited, &line);
	if (x < 0 || y < 0)
		free_env(&fl_env, WRONG_FORMAT);
	load_new_map(fl_env, (size_t)x, (size_t)y);
}

void			load_new_map(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	char			**res;
	char			*tmp;
	size_t			index_y;

	fl_verify_header_map(fl_env, size_x);
	ft_memcheck(res = (char **)malloc(sizeof(char *) * (size_y)));
	index_y = 0;
	while (index_y < size_y)
	{
		get_next_line(0, &tmp, fl_env->env_gnl);
		if (fl_verify_each_line_map(tmp, index_y, size_x) == FALSE)
		{
			free(tmp);
			fl_free_tab_strings(&res, index_y);
			free_env(&fl_env, WRONG_FORMAT);
		}
		res[index_y] = interpret_line(tmp + 4);
		index_y++;
		free(tmp);
	}
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
