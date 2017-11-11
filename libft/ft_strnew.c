/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:43:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	index;

	index = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
	s[index] = 0;
	return (s);
}
