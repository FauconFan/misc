/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:41:57 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 17:57:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		size_multiple_n(size_t *new_len, size_t n)
{
	if (*new_len % n != 0)
		*new_len += n - (*new_len % n);
}

void			size_multiple_16(size_t *new_len)
{
	size_multiple_n(new_len, 16);
}

void			size_multiple_page(size_t *new_len)
{
	size_multiple_n(new_len, (size_t)getpagesize());
}

t_bool			size_ok(size_t l)
{
	return ((l >> 56) != 0);
}
