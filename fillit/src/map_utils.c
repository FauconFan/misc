/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:59:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/11 14:25:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int 	is_in_map(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->size && y >= 0 && y < map->size);
}

int 	piece_placable(t_map **map, t_piece_tetris_simp *piece, int x, int y)
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		if ((is_in_map(*map, piece->x[i] + x, piece->y[i] + y) == 1 &&
			(*map)->map[piece->x[i] + x][piece->y[i] + y] == '.') == 0)
			return (0);
		i++;
	}
	return (1);
}

void 	place_piece(t_map **map, t_piece_tetris_simp *piece, int x, int y)
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		(*map)->map[piece->x[i] + x][piece->y[i] + y] = piece->id;
		i++;
	}
}

void 	remove_piece(t_map **map, t_piece_tetris_simp *piece, int x, int y)
{int 	i;

	i = 0;
	while (i < 4)
	{
		(*map)->map[piece->x[i] + x][piece->y[i] + y] = '.';
		i++;
	}
}