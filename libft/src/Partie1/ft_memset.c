/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:51:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:45:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;
	size_t	index;

	index = 0;
	d = (char *)s;
	while (index < n)
	{
		d[index] = (char)c;
		index++;
	}
	return (s);
}
