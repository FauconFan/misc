/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:11:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 16:29:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include "init_utils.h"
#include "piece_tetris.h"
#include "piece_tetris_utils.h"

int 	main(int argc, char **argv)
{
	t_piece_tetris	**pieces;

	if (argc != 2)
		die("Usage : ./fillit [file]");
	pieces = init(argv[1]);
	print_pieces(pieces);
	free_pieces(pieces);
	return (0);
}