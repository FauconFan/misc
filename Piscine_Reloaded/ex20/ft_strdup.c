/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:21:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 12:32:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		index;
	int		length;
	char	*res;

	length = 0;
	while (*(src + length))
		length++;
	if ((res = (char *)malloc(length + 1)) == NULL)
		return (0);
	index = 0;
	while (index < length)
	{
		res[index] = src[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
