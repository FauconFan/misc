/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:04:30 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:26:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_UTILS_H
# define INIT_UTILS_H

# include <stdlib.h>
# include "init.h"
# include "piece_tetris_simp.h"

void						die(char *str);
int							is_in_buf(int x, int y);
t_piece_tetris_simp			**init_pieces();
void						print_pieces(t_piece_tetris_simp **pieces);
void						free_pieces(t_piece_tetris_simp **pieces);

#endif
