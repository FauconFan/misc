/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:39:21 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 14:18:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_blk	*ft_ph_alloc(t_ph *ph, t_len *len, size_t mult, t_ph **cache)
{
	t_blk		*block;
	void		*v;

	block = (t_blk *)(ph + 1);
	v = ft_blk_alloc(block, ph->len_page - sizeof(t_ph), len);
	if (v != NULL)
		return (v);
	if (ph->next_page == NULL)
	{
		ph->next_page = ft_ph_new(len->len, mult, cache);
		if (ph->next_page == NULL)
			return (NULL);
	}
	return (ft_ph_alloc(ph->next_page, len, mult, cache));
}
