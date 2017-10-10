/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:21:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 10:20:26 by jpriou           ###   ########.fr       */
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
	res = (char*)malloc(length + 1);
	index = 0;
	while (index++ < length)
		res[index - 1] = src[index - 1];
	res[index] = '\0';
	return (res);
}
