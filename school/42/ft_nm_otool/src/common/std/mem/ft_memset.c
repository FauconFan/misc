/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:40:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 10:42:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_memset(void *dest, size_t len, char c)
{
	char		*sdest;
	size_t		i;

	sdest = (char *)dest;
	i = 0;
	while (i < len)
	{
		sdest[i] = c;
		++i;
	}
}
