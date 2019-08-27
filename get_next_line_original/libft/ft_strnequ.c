/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:42:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (s1 == 0 || s2 == 0)
		return (-1);
	index = 0;
	while (s1[index] == s2[index] && index < n)
	{
		if (s1[index] == 0)
			return (1);
		index++;
	}
	if (index == n)
		return (1);
	return (0);
}
