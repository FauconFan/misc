/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_get_len_asked.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:25:52 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:10:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

inline size_t		ft_blk_get_len_asked(t_blk *blk)
{
	return ((((size_t)blk->len_asked3))
		| (((size_t)blk->len_asked2) << 32)
		| (((size_t)blk->len_asked1) << 48));
}
