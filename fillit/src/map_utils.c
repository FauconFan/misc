/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:59:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 18:45:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int 	is_in_map(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->size && y >= 0 && y < map->size);
}

int 	piece_placable(t_map **map, t_piece_tetris *piece, int x, int y)
{
	int 	compteur;
	int 	i;
	int 	j;

	compteur = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->rep[i][j] == '#')
			{
				compteur++;
				if ((is_in_map(*map, i + x, j + y) == 1 &&
					(*map)->map[i + x][j + y] == '.') == 0)
				{
					return (0);
				}
				if (compteur == 4)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void 	place_piece(t_map **map, t_piece_tetris *piece, int x, int y)
{
	int 	compteur;
	int 	i;
	int 	j;

	compteur = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->rep[i][j] == '#')
			{
				compteur++;
				(*map)->map[i + x][j + y] = piece->id;
				if (compteur == 4)
					return ;
			}
			j++;
		}
		i++;
	}
}

void 	remove_piece(t_map **map, t_piece_tetris *piece, int x, int y)
{
	int 	compteur;
	int 	i;
	int 	j;

	compteur = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->rep[i][j] == '#')
			{
				compteur++;
				(*map)->map[i + x][j + y] = '.';
				if (compteur == 4)
					return ;
			}
			j++;
		}
		i++;
	}
}