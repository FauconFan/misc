/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/11 13:20:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int 	try_backtracking_solve(t_map **map, t_piece_tetris_simp **pieces)
{
	int 	index[2];

	if (*pieces == 0)
		return (1);
	index[0] = 0;
	while (index[0] < (*map)->size)
	{
		index[1] = 0;
		while (index[1] < (*map)->size)
		{
			if (piece_placable(map, pieces[0], index[0], index[1]) == 1)
			{
				place_piece(map, pieces[0], index[0], index[1]);
				if (try_backtracking_solve(map, pieces + 1) == 1)
					return (1);
				remove_piece(map, pieces[0], index[0], index[1]);
			}
			index[1]++;
		}
		index[0]++;
	}
	return (0);
}

void 	solve_fillit(t_map **map, t_piece_tetris_simp **pieces)
{
	int 	size_actu;

	while (try_backtracking_solve(map, pieces) == 0)
	{
		size_actu = (*map)->size;
		free_map(*map);
		*map = new_map(size_actu + 1);
	}
	print_map(*map);
}