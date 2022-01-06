/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:42:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:53:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_blk	*ft_blk_find(t_blk *block, size_t remain, const void *ptr)
{
	if (ptr == (void *)(block + 1))
	{
		if (ft_blk_is_free(block))
			return (NULL);
		return (block);
	}
	if (remain < block->len_block)
		return (NULL);
	return (ft_blk_find(ft_blk_next(block), remain - block->len_block, ptr));
}
