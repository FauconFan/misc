/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:24:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/19 10:17:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (s1[index] - s2[index]);
}
