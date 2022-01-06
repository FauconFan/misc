/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:29:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:17:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_blk_print(t_blk *block, size_t remain, t_bool hexa)
{
	t_blk		*next;
	uint8_t		*begin;
	size_t		len;

	if (ft_blk_is_free(block) == FALSE)
	{
		len = ft_blk_get_len_asked(block);
		begin = (uint8_t *)(block + 1);
		ft_put_str("\t");
		ft_put_addr(begin);
		ft_put_str(" - ");
		ft_put_addr(begin + len);
		ft_put_str(" : ");
		ft_put_uint_ln(len);
		if (hexa)
			print_dump(begin, len);
	}
	if (block->len_block == 0)
		return ;
	if (block->len_block < remain)
	{
		next = (t_blk *)((char *)block + block->len_block);
		remain -= block->len_block;
		ft_blk_print(next, remain, hexa);
	}
}
