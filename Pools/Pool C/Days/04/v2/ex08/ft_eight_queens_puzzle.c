/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:37:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/15 15:50:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) ((x < 0) ? -x : x)

int		is_move_valid(int i, int j, int tab[8][8])
{
	int		x;
	int		y;

	x = 0;
	while (x < 8)
	{
		y = 0;
		while (y < 8)
		{
			if (tab[x][y] == 1)
			{
				if (x == i || y == j || ABS((x - i)) == ABS((y - j)))
				{
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		get_number(int tab[8][8], int row)
{
	int		col;
	int		res;

	if (row == 8)
	{
		return (1);
	}
	res = 0;
	col = 0;
	while (col < 8)
	{
		if (is_move_valid(col, row, tab) == 1)
		{
			tab[col][row] = 1;
			res += get_number(tab, row + 1);
			tab[col][row] = 0;
		}
		col++;
	}
	return (res);
}

int		ft_eight_queens_puzzle(void)
{
	int		tab[8][8];
	int		index[2];

	index[0] = 0;
	while (index[0] < 8)
	{
		index[1] = 0;
		while (index[1] < 8)
		{
			tab[index[0]][index[1]] = 0;
			index[1]++;
		}
		index[0]++;
	}
	return (get_number(tab, 0));
}
