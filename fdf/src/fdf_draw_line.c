/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:03:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 15:25:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_draw_line(int x[2], int y[2], t_env_fdf *env_fdf)
{
	double		dx;
	double		dy;
	int			isgrowing;
	int			tmp;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	isgrowing = (x[1] > x[0]) ? 1 : -1;
	tmp = x[0];
	while (tmp != x[1])
	{
		mlx_pixel_put(env_fdf->mlx_ptr, env_fdf->mlx_win,
			tmp, y[0] + dy * (tmp - x[0]) / dx, 0x00ffffff);
		tmp += isgrowing;
	}
	isgrowing = (y[1] > y[0]) ? 1 : -1;
	tmp = y[0];
	while (tmp != y[1])
	{
		mlx_pixel_put(env_fdf->mlx_ptr, env_fdf->mlx_win,
			x[0] + dx * (tmp - y[0]) / dy, tmp, 0x00ffffff);
		tmp += isgrowing;
	}
}

void	draw_2points(t_env_fdf *env_fdf, t_point_col *po1, t_point_col *po2)
{
	int		x[2];
	int		y[2];

	x[0] = (int)(po1->x_treated * env_fdf->matrix->x1 +
		po1->y_treated * env_fdf->matrix->x2 +
		po1->z_treated * env_fdf->matrix->x3 +
		env_fdf->matrix->additional_x);
	y[0] = (int)(po1->x_treated * env_fdf->matrix->y1 +
		po1->y_treated * env_fdf->matrix->y2 +
		po1->z_treated * env_fdf->matrix->y3 +
		env_fdf->matrix->additional_y);
	x[1] = (int)(po2->x_treated * env_fdf->matrix->x1 +
		po2->y_treated * env_fdf->matrix->x2 +
		po2->z_treated * env_fdf->matrix->x3 +
		env_fdf->matrix->additional_x);
	y[1] = (int)(po2->x_treated * env_fdf->matrix->y1 +
		po2->y_treated * env_fdf->matrix->y2 +
		po2->z_treated * env_fdf->matrix->y3 +
		env_fdf->matrix->additional_y);
	ft_mlx_draw_line(x, y, env_fdf);
}

void	treat_point(t_env_fdf *env, t_point_col *po)
{
	double		*coeff;

	coeff = env->actual_rotation;
	po->x_treated = po->x * (coeff[2] * coeff[4]) +
			po->y * (coeff[1] * coeff[3] * coeff[4] + coeff[0] * coeff[5]) +
			po->z * ( -coeff[3] * coeff[0] * coeff[4] + coeff[5] * coeff[1]);
	po->y_treated = po->x * (-coeff[2] * coeff[5]) +
			po->y * (-coeff[1] * coeff[3] * coeff[5] + coeff[0] * coeff[4]) +
			po->z * (coeff[2] * coeff[0] * coeff[5] + coeff[1] * coeff[4]);
	po->z_treated = po->x * (coeff[2]) +
			po->y * (-coeff[1] * coeff[2]) +
			po->z * (coeff[0] * coeff[2]);
}

void	draw_pixels(t_env_fdf *env_fdf)
{
	t_fdf_line	*line1;
	t_fdf_line	*line2;
	int			index;

	setup_env_actu_rotation(env_fdf);
	fdf_list_iter(env_fdf, &treat_point);
	mlx_clear_window(env_fdf->mlx_ptr, env_fdf->mlx_win);
	line1 = env_fdf->fdf_first_line;
	line2 = line1->next;
	while (line1)
	{
		index = -1;
		while (line1->list[++index + 1])
			draw_2points(env_fdf, line1->list[index], line1->list[index + 1]);
		if (line2)
		{
			index = -1;
			while (line1->list[++index])
				draw_2points(env_fdf, line1->list[index], line2->list[index]);
			line2 = line2->next;
		}
		line1 = line1->next;
	}
}
