/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:03:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 19:21:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_draw_line(int x1, int y1, int x2, int y2, t_env_fdf *env_fdf)
{
	double		dx;
	double		dy;
	int			isgrowing;
	int			tmp;

	dx = x2 - x1;
	dy = y2 - y1;
	isgrowing = (x2 > x1) ? 1 : -1;
	tmp = x1;
	while (tmp != x2)
	{
		mlx_pixel_put(env_fdf->mlx_ptr, env_fdf->mlx_win, tmp, y1 + dy * (tmp - x1) / dx, 0x00ffffff);
		tmp += isgrowing;
	}
	isgrowing = (y2 > y1) ? 1 : -1;
	tmp = y1;
	while (tmp != y2)
	{
		mlx_pixel_put(env_fdf->mlx_ptr, env_fdf->mlx_win, x1 + dx * (tmp - y1) / dy, tmp, 0x00ffffff);
		tmp += isgrowing;
	}
}

void	draw_between_two_points(t_env_fdf *env_fdf, t_point_col *po1, t_point_col *po2)
{
	int		x[2];
	int		y[2];

	x[0] = po1->x * env_fdf->matrix->x1 + po1->y * env_fdf->matrix->x2 + po1->z * env_fdf->matrix->x3 + env_fdf->matrix->additional_x;
	y[0] = po1->x * env_fdf->matrix->y1 + po1->y * env_fdf->matrix->y2 + po1->z * env_fdf->matrix->y3 + env_fdf->matrix->additional_y;
	x[1] = po2->x * env_fdf->matrix->x1 + po2->y * env_fdf->matrix->x2 + po2->z * env_fdf->matrix->x3 + env_fdf->matrix->additional_x;
	y[1] = po2->x * env_fdf->matrix->y1 + po2->y * env_fdf->matrix->y2 + po2->z * env_fdf->matrix->y3 + env_fdf->matrix->additional_y;
	ft_mlx_draw_line(x[0], y[0], x[1], y[1], env_fdf);
}

void	draw_pixels(t_env_fdf *env_fdf)
{
	t_fdf_line	*line1;
	t_fdf_line	*line2;
	int			index;

	line1 = env_fdf->fdf_first_line;
	line2 = line1->next;
	while (line1)
	{
		index = 0;
		while (line1->list[index + 1])
		{
			draw_between_two_points(env_fdf, line1->list[index], line1->list[index + 1]);
			index++;
		}
		if (line2)
		{
			index = 0;
			while (line1->list[index])
			{
				draw_between_two_points(env_fdf, line1->list[index], line2->list[index]);
				index++;
			}
			line2 = line2->next;
		}
		line1 = line1->next;
	}
}
