/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sym_sort_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:16:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 11:02:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	swap(t_sym *symbols, size_t i, size_t j)
{
	t_sym	tmp;

	if (i == j)
		return ;
	ft_memcpy(&tmp, symbols + i, sizeof(t_sym));
	ft_memcpy(symbols + i, symbols + j, sizeof(t_sym));
	ft_memcpy(symbols + j, &tmp, sizeof(t_sym));
}

static void	quicksort(t_sym *symbols, size_t beg, size_t end)
{
	size_t	frontier;
	size_t	i;

	if (beg >= end)
		return ;
	frontier = beg;
	i = beg;
	while (i < end)
	{
		if (ft_strcmp(symbols[i].name, symbols[end].name) < 0)
		{
			swap(symbols, i, frontier);
			frontier++;
		}
		++i;
	}
	swap(symbols, frontier, end);
	if (frontier != 0)
		quicksort(symbols, beg, frontier - 1);
	quicksort(symbols, frontier + 1, end);
}

void		ft_sym_sort_by_name(t_sym *symbols, size_t len)
{
	quicksort(symbols, 0, len - 1);
}
