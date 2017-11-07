/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:21:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 15:19:45 by jpriou           ###   ########.fr       */
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
	res = (char *)malloc(length + 1);
	if (res == NULL)
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
