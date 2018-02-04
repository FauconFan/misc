/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_algo_findbestmove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:17:55 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 18:38:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		update_nextmove(t_nextmove **res, t_nextmove **tmp)
{
	if (*tmp != NULL)
	{
		if (*res == NULL)
			*res = *tmp;
		else
		{
			if ((*res)->score < (*tmp)->score)
				free(*tmp);
			else
			{
				free(*res);
				*res = *tmp;
			}
		}
	}
}

t_nextmove		*find_nextmove(t_fillerenv *fl_env)
{
	t_nextmove		*res;
	t_nextmove		*tmp;
	int				y;
	int				x;

	res = NULL;
	tmp = NULL;
	y = 0 - fl_env->piece->size_y + 1;
	while (y < (int)(fl_env->size_y + fl_env->piece->size_y - 1))
	{
		x = 0 - fl_env->piece->size_x + 1;
		while (x < (int)(fl_env->size_x + fl_env->piece->size_x - 1))
		{
			tmp = init_nextmove(fl_env, x, y);
			update_nextmove(&res, &tmp);
			x++;
		}
		y++;
	}
	return (res);
}
