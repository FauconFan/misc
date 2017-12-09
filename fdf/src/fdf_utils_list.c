/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:18:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 08:39:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_list_iter(
			t_env_fdf *env,
			void (*f)(t_env_fdf *env, t_point_col *po))
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

void	get_highest_or_littlest(t_env_fdf *env, int *min, int *max)
{
	t_fdf_line	*line;
	int			index;

	line = env->fdf_first_line;
	*min = line->list[0]->z;
	*max = line->list[0]->z;
	while (line)
	{
		index = 0;
		while (line->list[index])
		{
			*min = ft_min(*min, line->list[index]->z);
			*max = ft_max(*max, line->list[index]->z);
			index++;
		}
		line = line->next;
	}
}

void	treat_points_for_display_well(t_env_fdf *env)
{
	int			values[2];
	t_fdf_line	*line;
	int			index;
	int			color[6];

	get_highest_or_littlest(env, values + 0, values + 1);
	ft_printf("Min value : %d\n", values[0]);
	ft_printf("Max value : %d\n", values[1]);
	line = env->fdf_first_line;
	build_rep(env->min_color, env->max_color, color);
	while (line)
	{
		index = 0;
		while (line->list[index])
		{
			line->list[index]->x -= env->size_x / 2;
			line->list[index]->y -= env->size_y / 2;
			if (line->list[index]->is_changeable)
				line->list[index]->color = build_color(color,
					line->list[index]->z - values[0],
					values[1] - values[0]);
			index++;
		}
		line = line->next;
	}
}

void	build_rep(int color1, int color2, int *rep)
{
	rep[0] = color1 >> 16 & 0xFF;
	rep[1] = color1 >> 8 & 0xFF;
	rep[2] = color1 & 0xFF;
	rep[3] = color2 >> 16 & 0xFF;
	rep[4] = color2 >> 8 & 0xFF;
	rep[5] = color2 & 0xFF;
}
