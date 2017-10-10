/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:05:11 by adavoine          #+#    #+#             */
/*   Updated: 2017/08/23 21:46:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include <stdlib.h>
#include "functions.h"
#define MIN(a, b) ((a < b) ? a : b)

int		is_in_square(int x, int y, t_sol *sol)
{
	if (x >= sol->x && x < sol->x + sol->size)
	{
		if (y >= sol->y && y < sol->y + sol->size)
			return (1);
	}
	return (0);
}

int		min(int a, int b, int c)
{
	return (MIN(MIN(a, b), MIN(a, c)));
}

void	ft_solve(t_grid *resultat, t_sol *sol)
{
	int	**tab;
	int y;
	int x;

	tab = resultat->tab;
	y = resultat->height - 1;
	while (y >= 0)
	{
		x = resultat->length - 1;
		while (x >= 0)
		{
			if (tab[y][x] != 0)
			{
				if ((x + 1) >= resultat->length || (y + 1) >= resultat->height)
					tab[y][x] = 1;
				else
					tab[y][x] = 1 + min(tab[y + 1][x], tab[y][x + 1],
							tab[y + 1][x + 1]);
				check_update_sol(sol, y, x, tab[y][x]);
			}
			x--;
		}
		y--;
	}
}

void	check_update_sol(t_sol *sol, int y, int x, int size)
{
	if (size >= sol->size)
	{
		sol->size = size;
		sol->x = x;
		sol->y = y;
	}
}

t_sol	*init_sol(void)
{
	t_sol	*res;

	res = (t_sol *)malloc(sizeof(t_sol));
	res->x = -1;
	res->y = -1;
	res->size = -1;
	return (res);
}
