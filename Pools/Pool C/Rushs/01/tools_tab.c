/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 12:36:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/13 13:03:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int		**build_tab(char **argv)
{
	int		**tab;
	int		index[2];
	char	c;

	index[0] = 0;
	tab = (int **)malloc(sizeof(int **) * 9);
	while (index[0] < 9)
	{
		index[1] = 0;
		tab[index[0]] = (int *)malloc(sizeof(int *) * 9);
		while (index[1] < 9)
		{
			c = argv[index[0]][index[1]];
			if (c == '.')
				tab[index[0]][index[1]] = 0;
			else
				tab[index[0]][index[1]] = c - '0';
			index[1]++;
		}
		index[0]++;
	}
	return (tab);
}

int		**cpy_tab(int **tab)
{
	int		**cpy;
	int		index[2];

	index[0] = 0;
	cpy = (int **)malloc(sizeof(int **) * 9);
	while (index[0] < 9)
	{
		index[1] = 0;
		cpy[index[0]] = (int *)malloc(sizeof(int *) * 9);
		while (index[1] < 9)
		{
			cpy[index[0]][index[1]] = tab[index[0]][index[1]];
			index[1]++;
		}
		index[0]++;
	}
	return (cpy);
}

int		cmp_tab(int **tab1, int **tab2)
{
	int		index[2];

	index[0] = 0;
	while (index[0] < 9)
	{
		index[1] = 0;
		while (index[1] < 9)
		{
			if (tab1[index[0]][index[1]] != tab2[index[0]][index[1]])
				return (0);
			index[1]++;
		}
		index[0]++;
	}
	return (1);
}
