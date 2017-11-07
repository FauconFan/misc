/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:40:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 09:23:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		index;
	int		*res;

	if (min >= max)
		return (0);
	res = (int*)malloc(4 * (max - min));
	index = 0;
	while (index < max - min)
	{
		res[index] = min + index;
		index++;
	}
	return (res);
}
