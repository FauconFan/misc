/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:09:44 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/16 12:02:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_bool		move(long c, t_select *env)
{
	if (c == RIGHT_KEY)
		env->index_selected = (env->index_selected + 1);
	else if (c == LEFT_KEY)
		env->index_selected = (env->index_selected - 1);
	else if (c == UP_KEY)
		env->index_selected = (env->index_selected - env->cols);
	else if (c == DOWN_KEY)
		env->index_selected = (env->index_selected + env->cols);
	else
		return (FALSE);
	env->index_selected += env->tot_args;
	env->index_selected %= env->tot_args;
	return (TRUE);
}
