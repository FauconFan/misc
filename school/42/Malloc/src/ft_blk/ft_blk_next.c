/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:13:46 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:27:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

inline t_blk	*ft_blk_next(t_blk *blk)
{
	t_blk	*next;

	next = (t_blk *)(((char *)blk) + blk->len_block);
	return (next);
}
