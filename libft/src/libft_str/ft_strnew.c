/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:43:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 10:04:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	index;

	index = 0;
	MEMCHECK((s = (char *)malloc(sizeof(char) * (size + 1))));
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
	s[index] = 0;
	return (s);
}
