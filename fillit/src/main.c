/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:11:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:22:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece_tetris_simp.h"
#include "main_utils.h"
#include "init.h"
#include "init_utils.h"
#include "map.h"
#include "solver.h"

int		main(int argc, char **argv)
{
	t_piece_tetris_simp	**pieces;
	t_map				*map;

	if (argc != 2)
		die("Usage : ./fillit [input_file]");
	pieces = init(argv[1]);
	map = new_map(get_good_size(get_number_of_pieces(pieces)));
	solve_fillit(map, pieces);
	free_pieces(pieces);
	return (0);
}
