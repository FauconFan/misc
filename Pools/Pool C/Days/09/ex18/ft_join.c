/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:24:50 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 14:45:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		my_strlen(char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*my_strncat(char *tab, char *src)
{
	while (*src)
	{
		*tab = *src;
		tab++;
		src++;
	}
	return (tab);
}

char	*ft_join(char **tab, char *sep)
{
	char	*res;
	char	*cpy;
	int		length;
	int		index[3];

	if (tab == 0)
		return (0);
	length = 0;
	index[0] = 0;
	while (tab[index[0]])
		length += my_strlen(tab[index[0]++]);
	length += my_strlen(sep) * (index[0] - 1) + 1;
	index[0] = 1;
	res = (char *)malloc(sizeof(char *) * length);
	cpy = res;
	cpy = my_strncat(cpy, tab[0]);
	while (tab[index[0]])
	{
		cpy = my_strncat(cpy, sep);
		cpy = my_strncat(cpy, tab[index[0]]);
		index[0]++;
	}
	*cpy = '\0';
	return (res);
}
