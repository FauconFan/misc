/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:11:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 17:18:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include "init_utils.h"
#include "piece_tetris.h"
#include "piece_tetris_utils.h"
#include "map.h"

int 	main(int argc, char **argv)
{
	t_piece_tetris	**pieces;
	t_map			*map;

	if (argc != 2)
		die("Usage : ./fillit [input_file]");
	pieces = init(argv[1]);
	map = new_map(10);
	print_map(map);
	free_map(map);
	free_pieces(pieces);
	return (0);
}