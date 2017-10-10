/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:50:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 16:23:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece_tetris_utils.h"

/**
 *	this method remove every grouped '.' unseless on the left.
 */
static void 	simplify_piece_verti(t_piece_tetris *piece)
{
	int 	index;

	while (piece->rep[0][0] == '.' && piece->rep[1][0] == '.' &&
			piece->rep[2][0] == '.' && piece->rep[3][0] == '.')
	{
		index = 0;
		while (index < 4)
		{
			piece->rep[index][0] = piece->rep[index][1];
			piece->rep[index][1] = piece->rep[index][2];
			piece->rep[index][2] = piece->rep[index][3];
			piece->rep[index][3] = '.';
			index++;
		}
	}
}

/**
 *	this method remove every single '.' useless on the top
 */
static void 	simplify_piece_horiz(t_piece_tetris *piece)
{
	char 	*tmp;

	while (ft_strequ(piece->rep[0], "....") == 1)
	{
		tmp = piece->rep[0];
		piece->rep[0] = piece->rep[1];
		piece->rep[1] = piece->rep[2];
		piece->rep[2] = piece->rep[3];
		piece->rep[3] = tmp;
	}
}

void 			simplify_piece(t_piece_tetris *piece)
{
	simplify_piece_verti(piece);
	simplify_piece_horiz(piece);
}