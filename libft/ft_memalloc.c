/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:25:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:51:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	size_t	index;

	index = 0;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		return (NULL);
	while (index < size)
	{
		tmp[index] = 0;
		index++;
	}
	return ((void *)tmp);
}
