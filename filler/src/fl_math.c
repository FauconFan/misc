/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:55:43 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 18:23:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double		my_sqrt(double n)
{
	double res;

	res = n;
	while ((res * res >= n + PRECISION_SQRT) ||
		(res * res <= n - PRECISION_SQRT))
	{
		res = (res + n / res) / 2;
	}
	return (res);
}

double		norme(int x1, int y1, int x2, int y2)
{
	int		res;
	int		dx;
	int		dy;

	dx = x2 - x1;
	dy = y2 - y1;
	res = dx * dx + dy * dy;
	return (my_sqrt((double)res));
}
