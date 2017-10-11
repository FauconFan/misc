/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:59:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/11 17:18:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS
# define MAP_UTILS

# include "map.h"
# include "piece_tetris_simp.h"
# include "libft.h"

int 	piece_placable(t_map *map, t_piece_tetris_simp *piece, int x, int y);
void 	place_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y);
void 	remove_piece(t_map *map, t_piece_tetris_simp *piece, int x, int y);

#endif