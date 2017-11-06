/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:48:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:45:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*d1;
	char	*d2;
	size_t	index;

	d1 = (char *)s1;
	d2 = (char *)s2;
	index = 0;
	while (*d1 == *d2 && index < n)
	{
		d1++;
		d2++;
		index++;
	}
	if (index == n)
		return (0);
	return (*(unsigned char *)d1 - *(unsigned char *)d2);
}
