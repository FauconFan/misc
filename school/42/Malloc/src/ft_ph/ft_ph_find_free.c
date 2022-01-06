/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_find_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:39:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:52:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t			ft_ph_find_free(t_ph *ph, void *ptr)
{
	t_blk		*block;
	size_t		remain;

	if (ph == NULL || ptr == NULL)
		return (0);
	if (ft_ph_is_in_page(ph, ptr))
	{
		block = (t_blk *)(ph + 1);
		remain = ph->len_page - sizeof(t_ph);
		return (ft_blk_find_free(block, remain, ptr));
	}
	return (ft_ph_find_free(ph->next_page, ptr));
}
