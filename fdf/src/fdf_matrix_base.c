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

void		ft_init_matrix(t_env_fdf *fdf)
{
	int		factor;

	factor = (ft_min(WIDTH_WINDOW, HEIGHT_WINDOW) / ft_min(fdf->size_x, fdf->size_y)) / 2;
	ft_memcheck((fdf->matrix = (t_matrix_base *)malloc(sizeof(t_matrix_base))));
	fdf->matrix->x1 = factor;
	fdf->matrix->x2 = 0.0;
	fdf->matrix->x3 = 0.0;
	fdf->matrix->y1 = 0.0;
	fdf->matrix->y2 = factor;
	fdf->matrix->y3 = 0.0;
	fdf->matrix->additional_x = WIDTH_WINDOW / 2;
	fdf->matrix->additional_y = HEIGHT_WINDOW / 2;
}
