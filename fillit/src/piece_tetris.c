/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:24:12 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 15:52:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "piece_tetris.h"
#include "piece_tetris_utils.h"
#include "init.h"
#include "libft.h"

/**
 *	Create new piece with a initialized is, it does nothing for rep...
 */
t_piece_tetris	*new_piece()
{
	static char 	count_id = INIT_ID;
	t_piece_tetris	*res;
	if ((res = (t_piece_tetris *)malloc(sizeof(t_piece_tetris))) == NULL)
		die("Wrong malloc !");
	res->id = count_id;
	res->rep = (char **)malloc(sizeof(char *) * 4);
	if ((res->rep) == NULL)
		die("Wrong malloc !");
	count_id++;
	return (res);
}

/**
 *	Initialize the piece with the specific string.
 */
t_piece_tetris	*init_piece(char *str)
{
	t_piece_tetris	*res;

	res = new_piece();
	res->rep[0] = ft_strsub(str, 0, 4);
	res->rep[1] = ft_strsub(str, 5, 4);
	res->rep[2] = ft_strsub(str, 10, 4);
	res->rep[3] = ft_strsub(str, 15, 4);
	free(str);
	simplify_piece(res);
	return (res);
}

/**
 *	print the piece.
 */
void 			print_piece(t_piece_tetris *piece)
{
	ft_putendl(piece->rep[0]);
	ft_putendl(piece->rep[1]);
	ft_putendl(piece->rep[2]);
	ft_putendl(piece->rep[3]);
}

/**
 *	free the piece.
 */
void			free_piece(t_piece_tetris *piece)
{
	free(piece->rep[0]);
	free(piece->rep[1]);
	free(piece->rep[2]);
	free(piece->rep[3]);
	free(piece->rep);
	free(piece);
}