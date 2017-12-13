/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:11:24 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 08:32:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			free_lines(t_fdf_line *line)
{
	int		index;

	if (line)
	{
		free_lines(line->next);
		index = 0;
		while (line->list[index])
		{
			free(line->list[index]);
			index++;
		}
		free(line->list);
		free(line);
	}
}

void			setup_env_actu_rotation(t_env_fdf *res)
{
	res->actual_rotation[0] = cos(res->rotation_x);
	res->actual_rotation[1] = sin(res->rotation_x);
	res->actual_rotation[2] = cos(res->rotation_y);
	res->actual_rotation[3] = sin(res->rotation_y);
	res->actual_rotation[4] = cos(res->rotation_z);
	res->actual_rotation[5] = sin(res->rotation_z);
}

t_env_fdf		*init_env_fdf(int color_values[2], int is_iso)
{
	t_env_fdf	*res;

	ft_memcheck((res = (t_env_fdf *)malloc(sizeof(t_env_fdf))));
	res->mlx_ptr = 0;
	res->mlx_win = 0;
	res->env_gnl = 0;
	res->fdf_first_line = 0;
	res->matrix = 0;
	res->rotation_x = (is_iso) ? -M_PI / 8 : 0;
	res->rotation_y = (is_iso) ? -M_PI / 8 : 0;
	res->rotation_z = (is_iso) ? 0 : 0;
	res->actual_rotation[0] = 0;
	res->actual_rotation[1] = 0;
	res->actual_rotation[2] = 0;
	res->actual_rotation[3] = 0;
	res->actual_rotation[4] = 0;
	res->actual_rotation[5] = 0;
	res->min_color = color_values[0];
	res->max_color = color_values[1];
	return (res);
}

void			free_env_fdf(t_env_fdf **env_fdf)
{
	t_env_fdf	*fdf;

	fdf = *env_fdf;
	if (fdf->mlx_ptr != 0 && fdf->mlx_win != 0)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->mlx_win);
		fdf->mlx_win = 0;
		fdf->mlx_ptr = 0;
	}
	if (fdf->fdf_first_line != 0)
	{
		free_lines(fdf->fdf_first_line);
	}
	if (fdf->matrix)
		free(fdf->matrix);
	if (fdf->env_gnl)
		free_env_gnl(fdf->env_gnl);
	*env_fdf = 0;
}
