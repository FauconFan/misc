/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_find_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:28:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:27:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_bool	fusion_with_next(t_blk *prev, size_t remain)
{
	t_blk	*actu;

	if (remain <= prev->len_block)
		return (FALSE);
	actu = ft_blk_next(prev);
	if (ft_blk_is_free(prev) == FALSE
		|| ft_blk_is_free(actu) == FALSE)
		return (FALSE);
	prev->len_block += actu->len_block;
	return (TRUE);
}

static size_t	search_free(t_blk *prev, size_t remain, void *ptr)
{
	size_t	res;
	t_blk	*actu;

	if (remain <= prev->len_block)
		return (0);
	actu = ft_blk_next(prev);
	if (ptr == (void *)(actu + 1))
	{
		res = ft_blk_get_len_asked(actu);
		ft_blk_set_free(actu);
		if (fusion_with_next(prev, remain))
			fusion_with_next(prev, remain);
		else
			fusion_with_next(actu, remain - prev->len_block);
		return (res);
	}
	return (search_free(actu, remain - prev->len_block, ptr));
}

size_t			ft_blk_find_free(t_blk *block, size_t remain, void *ptr)
{
	size_t	res;
	t_blk	*actu;

	if (ptr == (void *)(block + 1))
	{
		res = ft_blk_get_len_asked(block);
		if (remain <= block->len_block)
			ft_blk_set_free(block);
		actu = ft_blk_next(block);
		if (ft_blk_is_free(actu))
		{
			ft_blk_set_free(block);
			block->len_block += actu->len_block;
		}
		else
			ft_blk_set_free(block);
		return (res);
	}
	return (search_free(block, remain, ptr));
}
