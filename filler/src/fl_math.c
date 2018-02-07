/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:55:43 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/07 12:15:53 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static double		distance_euclidienne(int x1, int y1, int x2, int y2)
{
	double		res;
	int			dx;
	int			dy;
	int			n;

	dx = x2 - x1;
	dy = y2 - y1;
	res = (double)dx * dx + dy * dy;
	n = res;
	while ((res * res >= n + PRECISION_SQRT) ||
		(res * res <= n - PRECISION_SQRT))
	{
		res = (res + n / res) / 2;
	}
	return (res);
}

static double		distance_manhattan(int x1, int y1, int x2, int y2)
{
	int		res;

	res = 0;
	res += ft_abs(x1 - x2);
	res += ft_abs(y1 - y2);
	return ((double)res);
}

double				norme(int x1, int y1, int x2, int y2)
{
	if (MODE_CALCULUS_D == MODE_EUCLIDEAN)
		return (distance_euclidienne(x1, y1, x2, y2));
	else if (MODE_CALCULUS_D == MODE_MANHATTAN)
		return (distance_manhattan(x1, y1, x2, y2));
	return (distance_euclidienne(x1, y1, x2, y2));
}
