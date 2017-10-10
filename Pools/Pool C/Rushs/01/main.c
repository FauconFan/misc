/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:43:58 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/13 16:52:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	do_main(int **tab)
{
	int		**tab1;
	int		**tab2;

	tab1 = cpy_tab(tab);
	tab2 = cpy_tab(tab);
	if (backtracking_sudoku(tab1, 0, 1) == 1
			&& backtracking_sudoku(tab2, 0, 9) == 1
			&& cmp_tab(tab1, tab2) == 1)
		print_tab(tab1);
	else
		print_str(ERROR_STRING);
}

int		backtracking_sudoku(int **tab, int rank, int start)
{
	int		i;
	int		j;
	int		value;

	if (rank == 81)
		return (1);
	i = rank % 9;
	j = rank / 9;
	if (tab[i][j] > 0)
		return (backtracking_sudoku(tab, rank + 1, start));
	value = start;
	while (value % 10 != 0)
	{
		if (is_move_valid(value, i, j, tab) == 1)
		{
			tab[i][j] = value;
			if (backtracking_sudoku(tab, rank + 1, start) == 1)
				return (1);
			tab[i][j] = 0;
		}
		value = (start == 1) ? value + 1 : value - 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 10)
	{
		argc--;
		argv++;
	}
	if (argc == 9
			&& ft_just_chiffre(argv) == 1
			&& ft_verf_ligne(argv) == 1
			&& ft_verf_col(argv) == 1
			&& ft_verf_carre(argv) == 1)
	{
		do_main(build_tab(argv));
	}
	else
	{
		print_str(ERROR_STRING);
	}
	return (0);
}
