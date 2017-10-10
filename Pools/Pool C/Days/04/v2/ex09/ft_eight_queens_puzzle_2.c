/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:59:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/15 16:03:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) ((x < 0) ? -x : x)

void	ft_putchar(char c);
int		is_move_valid(int i, int j, int tab[8][8]);
void	get_number(int tab[8][8], int row);
void	print_tab(int tab[8][8]);

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

void	get_number(int tab[8][8], int col)
{
	int		row;

	if (col == 8)
	{
		print_tab(tab);
	}
	row = 0;
	while (row < 8)
	{
		if (is_move_valid(col, row, tab) == 1)
		{
			tab[col][row] = 1;
			get_number(tab, col + 1);
			tab[col][row] = 0;
		}
		row++;
	}
}

void	print_tab(int tab[8][8])
{
	int		index[2];
	char	c;

	index[0] = 0;
	while (index[0] < 8)
	{
		index[1] = 0;
		while (index[1] < 8)
		{
			if (tab[index[0]][index[1]] == 1)
			{
				c = index[1] + '0' + 1;
				ft_putchar(c);
				break ;
			}
			index[1]++;
		}
		index[0]++;
	}
	ft_putchar('\n');
}

void	ft_eight_queens_puzzle_2(void)
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
	get_number(tab, 0);
}
