/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_find_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:39:21 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:56:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_blk	*ft_ph_find_alloc(t_ph *ph, size_t len, size_t mult)
{
	t_blk		*block;
	void		*v;

	block = (t_blk *)(ph + 1);
	v = ft_blk_find_alloc(block, ph->len_page - sizeof(t_ph), len);
	if (v != NULL)
		return (v);
	if (ph->next_page == NULL)
	{
		ph->next_page = ft_ph_new(len, mult);
		if (ph->next_page == NULL)
			return (NULL);
	}
	return (ft_ph_find_alloc(ph->next_page, len, mult));
}
