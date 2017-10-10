/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:29:05 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/06 08:46:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	check_forbidden_cases(int board[8][8]);

void	reinit(int board[8][8], int index_reinit)
{
	int		compteur[2];

	compteur[0] = 0;
	compteur[1] = 0;
	while (compteur[0] < 8)
	{
		compteur[1] = 0;
		while (compteur[1] < 8)
		{
			if (board[compteur[0]][compteur[1]] != 5)
			{
				board[compteur[0]][compteur[1]] = 0;
			}
			else if (board[compteur[0]][compteur[1]] == 5 && index_reinit > compteur[1])
			{
				board[compteur[0]][compteur[1]] = 0;
			}
			compteur[1]++;
		}
		compteur[0]++;
	}
	check_forbidden_cases(board);
}

void	check_forbidden_case(int board[8][8], int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		if (x != i)
		{
			board[x][i] = 1;
		}
	}
	while (j < 8)
	{
		if (y != j)
		{
			board[j][y] = 1;
		}
	}
}

void	check_forbidden_cases(int board[8][8])
{
	return ;
}

void	queens_puzzle(int *res, int board[8][8], int nb_queen)
{

}

void	display_board(int board[8][8])
{
	int		compteur[2];

	compteur[0] = 0;
	compteur[1] = 0;
	while (compteur[0] < 8)
	{
		compteur[1] = 0;
		while (compteur[1] < 8)
		{
			ft_putchar(board[compteur[1]][compteur[0]] + '0');
			compteur[1]++;
		}
		ft_putchar('\n');
		compteur[0]++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

int		ft_eight_queens_puzzle(void)
{
	int		res;
	int		board[8][8];
	int		compteur[2];

	compteur[0] = 0;
	compteur[1] = 0;
	while (compteur[0] < 8)
	{
		compteur[1] = 0;
		while (compteur[1] < 8)
		{
			board[compteur[0]][compteur[1]] = 0;
			compteur[1]++;
		}
		compteur[0]++;
	}
	board[0][0] = 5;
	board[1][0] = 5;
	board[1][1] = 2;
	board[5][7] = 5;
	display_board(board);
	reinit(board, 0);
	display_board(board);
	return (0);
}
