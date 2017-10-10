/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:30:43 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/24 09:54:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "grid.h"
#include <stdlib.h>

void	test_solve_print(char *data)
{
	t_grid	*res;
	t_sol	*sol;

	res = entry_test_and_build(data);
	if (res == 0)
	{
		ft_putstrerr("map error\n");
		return ;
	}
	sol = init_sol();
	ft_solve(res, sol);
	while (*data >= '0' && *data <= '9')
		data++;
	print_result(sol, res, data);
	free_grid(res);
	free(sol);
}

int		main(int argc, char **argv)
{
	int		index;
	char	*input;

	if (argc == 1)
	{
		input = get_input(0);
		test_solve_print(input);
		free(input);
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			input = get_file_input(argv[index]);
			if (input != 0)
			{
				test_solve_print(input);
				free(input);
			}
			index++;
		}
	}
	return (0);
}

void	print_result(t_sol *sol, t_grid *resultat, char *entry)
{
	int		y;
	int		x;

	y = sol->y;
	while (y < sol->y + sol->size)
	{
		x = sol->x;
		while (x < sol->x + sol->size)
		{
			entry[4 + y * (resultat->length + 1) + x] = *(entry + 2);
			x++;
		}
		y++;
	}
	ft_putstr(entry + 4);
}
