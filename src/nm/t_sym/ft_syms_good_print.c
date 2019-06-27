/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syms_good_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:30:52 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 13:46:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	partition_printable(
				t_sym *symbols,
				size_t len,
				size_t *limit)
{
	size_t	i;

	i = 0;
	*limit = 0;
	while (i < len)
	{
		if (symbols->c == '?')
		{
			ft_syms_swap(symbols, i, len - 1);
			--len;
		}
		else
		{
			ft_syms_swap(symbols, *limit, i);
			++*limit;
			++i;
		}
	}
}

void		ft_syms_good_print(
				t_sym *symbols,
				size_t len,
				void (*psym)(t_sym *))
{
	size_t	i;
	size_t	limit;

	partition_printable(symbols, len, &limit);
	ft_syms_sort(symbols, limit);
	i = 0;
	while (i < limit)
		psym(symbols + i++);
}
