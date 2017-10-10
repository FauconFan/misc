/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 14:22:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int		value;
	int		index;

	if (length == 0)
		return (0);
	value = tab[0];
	while (index < length)
	{
		if (tab[index] > value)
			value = tab[index];
		index++;
	}
	return (value);
}
