/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:11:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 17:30:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_utils.h"
#include "init.h"
#include "init_utils.h"
#include "piece_tetris.h"
#include "piece_tetris_utils.h"
#include "map.h"
#include "solver.h"

int 	main(int argc, char **argv)
{
	t_piece_tetris	**pieces;
	t_map			*map;

	if (argc != 2)
		die("Usage : ./fillit [input_file]");
	pieces = init(argv[1]);
	map = new_map(get_good_size(get_number_of_pieces(pieces)));
	solve_fillit(&map, pieces);
	free_map(map);
	free_pieces(pieces);
	return (0);
}