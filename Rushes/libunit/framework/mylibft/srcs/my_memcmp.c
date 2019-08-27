/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:48:10 by dwald             #+#    #+#             */
/*   Updated: 2016/12/02 11:41:57 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

int	my_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (n--)
	{
		if (c1[i] != c2[i])
			return ((c1[i]) - (c2[i]));
		i++;
	}
	return (0);
}
