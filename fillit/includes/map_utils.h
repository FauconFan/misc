/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:59:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:22:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "piece_tetris_simp.h"
# include "map.h"

int		piece_placable(t_map *map, t_piece_tetris_simp *piece, int x, int y);
void	place_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y);
void	remove_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y);

#endif
