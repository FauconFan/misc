/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:38:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:53:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_blk	*ft_ph_find(t_ph *ph, const void *ptr)
{
	t_blk		*block;
	size_t		remain;

	if (ph == NULL || ptr == NULL)
		return (NULL);
	if (ft_ph_is_in_page(ph, ptr))
	{
		block = (t_blk *)(ph + 1);
		remain = ph->len_page - sizeof(t_ph);
		return (ft_blk_find(block, remain, ptr));
	}
	return (ft_ph_find(ph->next_page, ptr));
}
