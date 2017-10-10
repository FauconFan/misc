/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_recognize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarreze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:59:50 by blarreze          #+#    #+#             */
/*   Updated: 2017/08/20 22:56:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"

int		ft_rush0n(char *str, int n)
{
	if (n == 0)
		return ((str[0] == 'o') ? 1 : 0);
	else if (n == 1)
		return ((str[0] == '/') ? 1 : 0);
	return ((str[0] == 'A') ? 1 : 0);
}

int		*ft_condition(char *str, int *tab)
{
	if (ft_rush0n(str, 0))
		tab[0] = 1;
	if (ft_rush0n(str, 1))
		tab[1] = 1;
	if (ft_rush0n(str, 2))
		tab[2] = 1;
	if (ft_rush0n(str, 3))
		tab[3] = 1;
	if (ft_rush0n(str, 4))
		tab[4] = 1;
	return (tab);
}

int		*id_recognize(char *str)
{
	int	*tab;
	int	i;
	int	n;

	if ((tab = (int *)malloc(sizeof(int *) * 7)) == NULL)
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	n = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	tab[5] = i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	tab[6] = n;
	return (ft_condition(str, tab));
}
