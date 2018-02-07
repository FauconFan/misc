/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_envutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:43:05 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/07 14:53:56 by fauconfan        ###   ########.fr       */
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
	res->is_first_player = TRUE;
	res->opposite_player = FALSE;
	res->env_gnl = init_env_gnl();
	res->mode = NOT_SET;
	res->list_oppositecases = NULL;
	return (res);
}

void			free_env(t_fillerenv **fl_env)
{
	if (fl_env != NULL && *fl_env != NULL)
	{
		free_map(*fl_env);
		free_piece(*fl_env);
		free_env_gnl((*fl_env)->env_gnl);
		free_list_opposite(*fl_env);
		free(*fl_env);
		*fl_env = NULL;
	}
}
