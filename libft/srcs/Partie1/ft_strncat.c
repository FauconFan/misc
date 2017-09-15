/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:46:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	index[2];

	index[0] = 0;
	index[1] = 0;
	if (src == 0 || *src == 0)
		return (dest);
	if (dest == 0)
		return (0);
	while (dest[index[0]])
		index[0]++;
	while (src[index[1]] && index[1] < n)
	{
		dest[index[0] + index[1]] = src[index[1]];
		index[1]++;
	}
	dest[index[0] + index[1]] = 0;
	return (dest);
}