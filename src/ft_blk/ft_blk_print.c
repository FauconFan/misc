/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:29:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 15:58:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_blk_print(t_blk *block, size_t remain)
{
	t_blk		*next;
	char		*begin;
	size_t		len;

	if (ft_blk_is_free(block) == FALSE)
	{
		len = ft_blk_get_len_asked(block);
		begin = (char *)(block + 1);
		ft_put_str("\t");
		ft_put_addr(begin);
		begin += len;
		ft_put_str(" - ");
		ft_put_addr(begin);
		ft_put_str(" : ");
		ft_put_uint_ln(len);
	}
	if (block->len_block == 0)
		return ;
	if (block->len_block < remain)
	{
		next = (t_blk *)((char *)block + block->len_block);
		remain -= block->len_block;
		ft_blk_print(next, remain);
	}
}
