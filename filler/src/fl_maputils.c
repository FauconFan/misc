/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:59 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 17:16:16 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		load_new_map(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	char			**res;
	size_t			index;

	ft_memcheck((res = (char **)malloc(sizeof(char *) * (size_y))));
	index = 0;
	while (index < size_y)
	{
		get_next_line(0, res + index, fl_env->env_gnl);
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
			ft_printf("%s\n", fl_env->map[index]);
			index++;
		}
	}
}
