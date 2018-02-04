/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_envutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:43:05 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 16:46:36 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fillerenv		*init_env(void)
{
	t_fillerenv		*res;

	ft_memcheck((res = (t_fillerenv *)malloc(sizeof(t_fillerenv))));
	res->map = NULL;
	res->size_x = 0;
	res->size_y = 0;
	res->piece = NULL;
	res->ai_id = 0;
	res->env_gnl = init_env_gnl();
	return (res);
}

void			free_env(t_fillerenv **fl_env)
{
	if (fl_env != NULL && *fl_env != NULL)
	{
		free_map(*fl_env);
		free_piece(*fl_env);
		free_env_gnl((*fl_env)->env_gnl);
		free(*fl_env);
		*fl_env = NULL;
	}
}
