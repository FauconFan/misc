/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_find_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:28:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 15:29:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_bool	fusion_with_next(t_blk *prev, size_t remain)
{
	if (remain <= prev->len_block)
		return (FALSE);
	if (ft_blk_is_free(prev) == FALSE
		|| ft_blk_is_free(NEXT_BLOCK(prev)) == FALSE)
		return (FALSE);
	prev->len_block += NEXT_BLOCK(prev)->len_block;
	return (TRUE);
}

static size_t	search_free(t_blk *prev, size_t remain, void *ptr)
{
	size_t	res;

	if (remain <= prev->len_block)
		return (0);
	if (ptr == (void *)(NEXT_BLOCK(prev) + 1))
	{
		res = NEXT_BLOCK(prev)->len_block;
		ft_blk_set_free(NEXT_BLOCK(prev));
		if (fusion_with_next(prev, remain))
			fusion_with_next(prev, remain);
		else
			fusion_with_next(NEXT_BLOCK(prev), remain - prev->len_block);
		return (res - sizeof(t_blk));
	}
	return (search_free(NEXT_BLOCK(prev), remain - prev->len_block, ptr));
}

size_t			ft_blk_find_free(t_blk *block, size_t remain, void *ptr)
{
	size_t	res;

	if (ptr == (void *)(block + 1))
	{
		res = block->len_block;
		if (remain <= block->len_block)
			ft_blk_set_free(block);
		else if (ft_blk_is_free(NEXT_BLOCK(block)))
		{
			ft_blk_set_free(block);
			block->len_block += NEXT_BLOCK(block)->len_block;
		}
		else
			ft_blk_set_free(block);
		return (res - sizeof(t_blk));
	}
	return (search_free(block, remain, ptr));
}
