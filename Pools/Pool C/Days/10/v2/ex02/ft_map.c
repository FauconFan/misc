/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:11:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 11:26:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*res;
	int		index;

	res = (int *)malloc(sizeof(int *) * length);
	index = 0;
	while (index < length)
	{
		res[index] = f(tab[index]);
		index++;
	}
	return (res);
}
