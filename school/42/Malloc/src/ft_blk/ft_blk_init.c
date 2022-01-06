/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:28:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/23 11:19:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_blk_init(void *v, size_t remain_tot)
{
	t_blk		*head_block;

	head_block = (t_blk *)v;
	head_block->len_block = remain_tot;
	ft_blk_set_free(head_block);
	head_block->len_asked = 0;
}
