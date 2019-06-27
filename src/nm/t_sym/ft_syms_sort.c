/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syms_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:16:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 13:30:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**	Lexicographic order
*/

static t_bool		sym_lessthan(t_sym *sym_a, t_sym *sym_b)
{
	int		res_cmp;

	res_cmp = ft_strcmp(sym_a->name, sym_b->name);
	if (res_cmp != 0)
		return (res_cmp < 0);
	return (sym_a->value < sym_b->value);
}

static void			quicksort(t_sym *symbols, size_t beg, size_t end)
{
	size_t	frontier;
	size_t	i;

	if (beg >= end)
		return ;
	frontier = beg;
	i = beg;
	while (i < end)
	{
		if (sym_lessthan(symbols + i, symbols + end))
		{
			ft_syms_swap(symbols, i, frontier);
			frontier++;
		}
		++i;
	}
	ft_syms_swap(symbols, frontier, end);
	if (frontier != 0)
		quicksort(symbols, beg, frontier - 1);
	quicksort(symbols, frontier + 1, end);
}

void				ft_syms_sort(t_sym *symbols, size_t len)
{
	quicksort(symbols, 0, len - 1);
}
