/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:04:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/12 10:58:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_utils.h"

t_piece_tetris_simp		**init_pieces()
{
	t_piece_tetris_simp	**res;
	int 	index;

	if ((res = (t_piece_tetris_simp **)
		malloc(sizeof(t_piece_tetris_simp *) * (SIZE_MAX + 1))) == NULL)
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

void				print_pieces(t_piece_tetris_simp **pieces)
{
	int 	index;

	index = 0;
	while (index < SIZE_MAXX)
	{
		if (pieces[index] != 0)
			print_piece_simp(pieces[index]);
		index++;
	}
}

void				free_pieces(t_piece_tetris_simp **pieces)
{
	int 	index;

	index = 0;
	while (index < SIZE_MAXX + 1)
	{
		if (pieces[index] != 0)
			free_piece_simp(pieces[index]);
		index++;
	}
	free(pieces);
}

/**
 *	Die function if there is an error, often this function is called with ERROR
 *	String constant.
 */
void			die(char *str)
{
	ft_putendl(str);
	exit(1);
}

/**
 *	Check is a couple is in the buffer - map
 */
int 			is_in_buf(int x, int y)
{
	return (x >= 0 && x < 4 && y >= 0 && y < 4);
}