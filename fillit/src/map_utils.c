/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:59:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:02:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

/*
** Do not call this function without in place_placble
** @param  map map of tetris
** @param  x   coords x
** @param  y   coords y
** @return     a bool 1 or 0
*/

static int	is_in_map(t_map *map, int x, int y)
{
	return (x < map->size && y < map->size);
}

int			piece_placable(t_map *map, t_piece_tetris_simp *piece, int x, int y)
{
	int		i;
	int		tmpx;
	int		tmpy;

	i = 0;
	while (i < 4)
	{
		tmpx = piece->x[i] + x;
		tmpy = piece->y[i] + y;
		if (is_in_map(map, tmpx, tmpy) == 0)
		{
			return (0);
		}
		else if (map->map[tmpx][tmpy] != '.')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void		place_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map->map[piece->x[i] + x][piece->y[i] + y] = piece->id;
		i++;
	}
}

void		remove_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map->map[piece->x[i] + x][piece->y[i] + y] = '.';
		i++;
	}
}
