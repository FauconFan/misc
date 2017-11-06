/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:44:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:47:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int 	index;
	char			*res;

	index = 0;
	while (s[index])
		index++;
	if ((res = (char *)malloc(sizeof(char) * (index + 1))) == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
