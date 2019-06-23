/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_set_occupied.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:21:36 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/23 11:19:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

inline void	ft_blk_set_occupied(t_blk *blk, size_t size)
{
	blk->free = FALSE;
	blk->len_asked = size;
}
