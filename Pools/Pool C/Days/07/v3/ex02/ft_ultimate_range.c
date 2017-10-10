/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:54:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 09:24:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		index;
	int		*tab;

	if (min >= max)
	{
		return (0);
	}
	index = 0;
	tab = (int*)malloc(4 * (max - min));
	while (index < max - min)
	{
		tab[index] = min + index;
		index++;
	}
	*range = tab;
	return (index);
}
