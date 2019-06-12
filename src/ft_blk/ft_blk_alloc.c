/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:26:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 15:54:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*search(
					t_blk *block,
					size_t remain,
					t_len *len)
{
	size_t len_next_block;

	if (ft_blk_is_free(block) && len->len <= block->len_block)
	{
		ft_blk_set_occupied(block, len->len_asked);
		len_next_block = block->len_block - len->len;
		block->len_block = len->len;
		if (len_next_block != 0)
			ft_blk_init((char *)block + block->len_block, len_next_block);
		return (block);
	}
	if (remain > block->len_block)
		return (search(NEXT_BLOCK(block), remain - block->len_block, len));
	return (NULL);
}

t_blk			*ft_blk_alloc(
					t_blk *block,
					size_t remain,
					t_len *len)
{
	return (search(block, remain, len));
}
