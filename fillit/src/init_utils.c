/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:04:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 16:53:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_utils.h"

t_piece_tetris		**init_pieces()
{
	t_piece_tetris	**res;
	int 	index;

	if ((res = (t_piece_tetris **)malloc(sizeof(t_piece_tetris *) * 26)) == NULL)
		die("Wrong malloc !");
	index = 0;
	while (index < SIZE_MAX)
	{
		res[index] = 0;
		index++;
	}
	return (res);
}

void				print_pieces(t_piece_tetris **pieces)
{
	int 	index;

	index = 0;
	while (index < SIZE_MAX)
	{
		if (pieces[index] != 0)
			print_piece(pieces[index]);
		index++;
	}
}

void				free_pieces(t_piece_tetris **pieces)
{
	int 	index;

	index = 0;
	while (index < SIZE_MAX)
	{
		if (pieces[index] != 0)
			free_piece(pieces[index]);
		index++;
	}
	free(pieces);
}