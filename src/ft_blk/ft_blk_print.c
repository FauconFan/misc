/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:29:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:51:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_blk_print(t_blk *block, size_t remain)
{
	t_blk		*next;

	ft_put_str("\tBLOCK => LEN = ");
	ft_put_uint(block->len_block);
	ft_put_str(", IS FREE = ");
	ft_put_str_ln(STR_OF_BOOL(block->is_free));
	if (block->len_block == 0)
		return ;
	if (block->len_block < remain)
	{
		next = (t_blk *)((char *)block + block->len_block);
		remain -= block->len_block;
		ft_blk_print(next, remain);
	}
}
