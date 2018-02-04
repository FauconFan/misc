/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:59 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 18:24:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		load_map(t_fillerenv *fl_env)
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

void		load_new_map(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	char			**res;
	char			*tmp;
	size_t			index;

	ft_memcheck((res = (char **)malloc(sizeof(char *) * (size_y))));
	index = 0;
	get_next_line(0, res, fl_env->env_gnl);
	free(*res);
	while (index < size_y)
	{
		get_next_line(0, &tmp, fl_env->env_gnl);
		res[index] = ft_strdup(tmp + 4);
		free(tmp);
		index++;
	}
	fl_env->map = res;
	fl_env->size_x = size_x;
	fl_env->size_y = size_y;
}

void		free_map(t_fillerenv *fl_env)
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

void		print_map(t_fillerenv *fl_env)
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
