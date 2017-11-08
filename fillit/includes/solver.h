/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:19:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:15:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "init_utils.h"
# include "map.h"
# include "piece_tetris_simp.h"
# include "map_utils.h"

void	solve_fillit(t_map *map, t_piece_tetris_simp **pieces);

#endif
