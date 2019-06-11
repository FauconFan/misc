/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_ph_find_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:39:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 10:23:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_bool	is_in_page(t_mlc_ph *ph, void *ptr)
{
	unsigned long long	begin;
	unsigned long long	end;
	unsigned long long	cand;
	t_bool				res;

	begin = (unsigned long long)ph;
	end = begin + ph->len_page;
	cand = (unsigned long long)ptr;
	res = cand >= begin && cand < end;
	return (res);
}

size_t			mlc_ph_find_free(t_mlc_ph *ph, void *ptr)
{
	t_mlc_block	*block;
	size_t		remain;

	if (ph == NULL || ptr == NULL)
		return (0);
	if (is_in_page(ph, ptr))
	{
		block = (t_mlc_block *)(ph + 1);
		remain = ph->len_page - sizeof(t_mlc_ph);
		return (mlc_block_find_free(block, remain, ptr));
	}
	return (mlc_ph_find_free(ph->next_page, ptr));
}
