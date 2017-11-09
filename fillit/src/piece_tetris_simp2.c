/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris_simp2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan </var/spool/mail/fauconfan>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:38:03 by fauconfan         #+#    #+#             */
/*   Updated: 2017/11/09 13:31:23 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece_tetris_simp.h"

t_piece_tetris_simp		**init_pieces(void)
{
	t_piece_tetris_simp	**res;
	int					index;

	if ((res = (t_piece_tetris_simp **)
		malloc(sizeof(t_piece_tetris_simp *) * (SIZE_MAXX + 1))) == NULL)
	{
		die("Wrong malloc !");
	}
	index = 0;
	while (index < SIZE_MAXX + 1)
	{
		res[index] = 0;
		index++;
	}
	return (res);
}

void					print_pieces(t_piece_tetris_simp **pieces)
{
	int		index;

	index = 0;
	while (index < SIZE_MAXX)
	{
		if (pieces[index] != 0)
			print_piece_simp(pieces[index]);
		index++;
	}
}

void					free_pieces(t_piece_tetris_simp **pieces)
{
	int		index;

	index = 0;
	while (index < SIZE_MAXX + 1)
	{
		if (pieces[index] != 0)
			free_piece_simp(pieces[index]);
		index++;
	}
	free(pieces);
}


