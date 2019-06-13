/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_set_occupied.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:21:36 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_blk_set_occupied(t_blk *blk, size_t size)
{
	blk->free = FALSE;
	blk->len_asked1 = (uint8_t)(size >> 48);
	blk->len_asked2 = (uint16_t)(size >> 32);
	blk->len_asked3 = (uint32_t)(size);
}
