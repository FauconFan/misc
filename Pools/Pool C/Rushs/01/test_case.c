/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:58:08 by lchancri          #+#    #+#             */
/*   Updated: 2017/08/13 16:36:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		is_on_column(int value, int j, int **tab)
{
	int a;

	a = 0;
	while (a < 9)
	{
		if (tab[a][j] == value)
			return (1);
		a++;
	}
	return (0);
}

int		is_on_row(int value, int i, int **tab)
{
	int a;

	a = 0;
	while (a < 9)
	{
		if (tab[i][a] == value)
			return (1);
		a++;
	}
	return (0);
}

int		is_on_square_treatment(int value, int a, int c, int **tab)
{
	int b;
	int d;

	b = a + 2;
	d = c + 2;
	while (a <= b)
	{
		while (c <= d)
		{
			if (tab[a][c] == value)
				return (1);
			c++;
		}
		c -= 3;
		a++;
	}
	return (0);
}

int		is_on_square(int value, int k, int **tab)
{
	int a;
	int c;

	if (k >= 1 && k <= 3)
		a = 0;
	else if (k >= 4 && k <= 6)
		a = 3;
	else
		a = 6;
	if (k == 1 || k == 4 || k == 7)
		c = 0;
	else if (k == 2 || k == 5 || k == 8)
		c = 3;
	else
		c = 6;
	return (is_on_square_treatment(value, a, c, tab));
}

int		is_move_valid(int value, int j, int i, int **tab)
{
	int k;

	k = (i / 3) + ((j / 3) * 3) + 1;
	if (is_on_column(value, i, tab) == 0
			&& is_on_row(value, j, tab) == 0
			&& is_on_square(value, k, tab) == 0)
		return (1);
	return (0);
}
