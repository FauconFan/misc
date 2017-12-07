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
	ft_memcheck((fdf->matrix = (t_matrix_base *)malloc(sizeof(t_matrix_base))));
	fdf->matrix->x1 = 50.0;
	fdf->matrix->x2 = 0.0;
	fdf->matrix->x3 = 0.0;
	fdf->matrix->y1 = 0.0;
	fdf->matrix->y2 = 50.0;
	fdf->matrix->y3 = 0.0;
	fdf->matrix->additional_x = WIDTH_WINDOW / 2 - fdf->matrix->x1 * fdf->size_x / 2;
	fdf->matrix->additional_y = HEIGHT_WINDOW / 2 - fdf->matrix->y2 * fdf->size_y / 2;
}
