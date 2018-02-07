/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_storeoppositecases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:49:07 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/07 15:37:16 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_each_elem(void *content)
{
	free(content);
}

void			free_list_opposite(t_fillerenv *fl_env)
{
	ft_lstfreeall(&(fl_env->list_oppositecases), free_each_elem);
}

void			store_one_point(t_fillerenv *fl_env, int x, int y)
{
	t_point		*pt;

	ft_memcheck((pt = (t_point *)malloc(sizeof(t_point))));
	pt->x = x;
	pt->y = y;
	ft_lstaddfront_nocpy(&(fl_env->list_oppositecases), pt);
}

void			calculate_list_opponent(t_fillerenv *fl_env)
{
	size_t		y;
	size_t		x;

	y = -1;
	while(++y < fl_env->size_y)
	{
		x = -1;
		while (++x < fl_env->size_x)
		{
			if (is_occupied_by_this_player(fl_env->map[y][x],
						fl_env->opposite_player))
			{
				if (((y == 0 || occ_opp(fl_env, y - 1, x)) &&
					(x == 0 || occ_opp(fl_env, y, x - 1)) &&
					(y == fl_env->size_y - 1 || occ_opp(fl_env, y + 1, x)) &&
					(x == fl_env->size_x - 1 || occ_opp(fl_env, y, x + 1))) == FALSE)
				{
					store_one_point(fl_env, x, y);
				}
			}
		}
	}
}

void			simple_display(void *content)
{
	t_point		*pt;

	pt = (t_point *)content;
	ft_printf("x : %d, y %d\n", pt->x, pt->y);
}
