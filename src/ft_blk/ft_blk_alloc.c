/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:26:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 13:49:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*search(t_blk *block, size_t remain, size_t size)
{
	size_t len_next_block;

	if (block->is_free && size <= block->len_block)
	{
		block->is_free = FALSE;
		len_next_block = block->len_block - size;
		block->len_block = size;
		if (len_next_block != 0)
			ft_blk_init((char *)block + block->len_block, len_next_block);
		return (block);
	}
	if (remain > block->len_block)
		return (search(NEXT_BLOCK(block), remain - block->len_block, size));
	return (NULL);
}

t_blk			*ft_blk_alloc(t_blk *block, size_t remain, size_t size)
{
	return (search(block, remain, size));
}
