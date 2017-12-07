/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:18:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 15:37:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_list_iter(t_env_fdf *env, void (*f)(t_env_fdf *env, t_point_col *po))
{
	t_fdf_line	*line;
	int			index;

	line = env->fdf_first_line;
	while (line)
	{
		index = 0;
		while (line->list[index])
		{
			f(env, line->list[index]);
			index++;
		}
		line = line->next;
	}
}

void	adapt_each_point(t_env_fdf *env, t_point_col *col)
{
	col->x -= env->size_x / 2;
	col->y -= env->size_y / 2;
}
