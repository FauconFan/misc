/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:09:44 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 17:28:04 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_bool		move(long c, t_select *env)
{
	if (c == RIGHT_KEY)
		env->index_selected = (env->index_selected + 1) % env->tot_args;
	else if (c == LEFT_KEY)
		env->index_selected = (env->index_selected + env->tot_args - 1) % env->tot_args;
	else if (c == UP_KEY)
		env->index_selected = (env->index_selected + env->tot_args - env->cols) % env->tot_args;
	else if (c == DOWN_KEY)
		env->index_selected = (env->index_selected + env->cols) % env->tot_args;
	else
		return (FALSE);
	return (TRUE);
}
