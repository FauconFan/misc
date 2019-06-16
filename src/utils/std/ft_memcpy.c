/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:01:43 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:32:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

inline void	ft_memcpy(void *dest, const void *src, size_t l)
{
	char		*d1;
	const char	*d2;
	size_t		index;

	index = 0;
	d1 = (char *)dest;
	d2 = (const char *)src;
	while (index < l)
	{
		d1[index] = d2[index];
		index++;
	}
}
