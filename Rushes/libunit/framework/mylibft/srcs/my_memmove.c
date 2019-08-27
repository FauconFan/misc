/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:23:56 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 11:56:56 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	*my_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 > s2)
	{
		str1 = str1 + n;
		str2 = str2 + n;
		while (n--)
			*--str1 = *--str2;
	}
	else
		my_memcpy(s1, s2, n);
	return (s1);
}
