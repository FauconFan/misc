/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:59:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/04 14:39:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		index;
	int		min;
	int		rank_min;
	int		tampon;

	if (size == 0)
		return ;
	index = 1;
	min = tab[0];
	rank_min = 0;
	while (index != size)
	{
		if (tab[index] < min)
		{
			min = tab[index];
			rank_min = index;
		}
		index++;
	}
	tampon = tab[0];
	tab[0] = min;
	tab[rank_min] = tampon;
	ft_sort_integer_table((tab + 1), size - 1);
}
