/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_good_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:09:51 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 14:24:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t			malloc_good_size(size_t size)
{
	size_multiple_16(&size);
	if (size > SMALL_MAX)
	{
		size_multiple_page(&size);
		size -= sizeof(t_ph) + sizeof(t_blk);
	}
	return (size);
}
