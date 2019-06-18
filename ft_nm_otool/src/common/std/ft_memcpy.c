/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:20:22 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 09:22:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*sdest;
	const char	*ssrc;
	size_t		i;

	sdest = (char *)dest;
	ssrc = (const char *)src;
	i = 0;
	while (i < len)
	{
		sdest[i] = ssrc[i];
		++i;
	}
}
