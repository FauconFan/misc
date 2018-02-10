/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_adapt_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:22:05 by jpriou            #+#    #+#             */
/*   Updated: 2018/02/07 13:57:30 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		not_set(t_fillerenv *fl_env)
{
	int		j;
	int		i;
	char	c;

	j = 0;
	while (j < (int)fl_env->size_y)
	{
		i = 0;
		while (i < (int)fl_env->size_x)
		{
			c = fl_env->map[j][i];
			if (c != EMPTY_CASE)
			{
				c = ft_toupper(c);
				if ((c == 'O' && fl_env->is_first_player) ||
					(c == 'X' && fl_env->is_first_player == FALSE))
					fl_env->mode = HIGHWAY_TO_HELL;
				else
					fl_env->mode = HIGHWAY_TO_SKY;
				return ;
			}
			i++;
		}
		j++;
	}
}

void			adapt_strategy(t_fillerenv *fl_env)
{
	int		i;
	char	*str;

	if (fl_env->mode == NOT_SET)
	{
		not_set(fl_env);
	}
	else if (fl_env->mode == HIGHWAY_TO_SKY || fl_env->mode == HIGHWAY_TO_HELL)
	{
		i = 0;
		if (fl_env->mode == HIGHWAY_TO_SKY)
			str = fl_env->map[0];
		else
			str = fl_env->map[fl_env->size_y - 1];
		while (i < (int)fl_env->size_x)
		{
			if (is_occupied_by_this_player(str[i], fl_env->is_first_player))
			{
				fl_env->mode = DEFAULT_MODE;
				return ;
			}
			i++;
		}
	}
}
