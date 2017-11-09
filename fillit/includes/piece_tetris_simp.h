/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris_simp.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:32:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/09 13:35:46 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TETRIS_SIMP_H
# define PIECE_TETRIS_SIMP_H

# include <stdlib.h>
# include "init_utils.h"
# include "libft.h"

# define INIT_ID	'A'
# define SIZE_MAXX	26

typedef struct					s_piece_tetris_simp
{
	char						id;
	short						x[4];
	short						y[4];
}								t_piece_tetris_simp;

t_piece_tetris_simp				*init_piece_simp(char *str);
void							print_piece_simp(t_piece_tetris_simp *piece);
void							free_piece_simp(t_piece_tetris_simp *piece);
t_piece_tetris_simp				**init_pieces();
void							print_pieces(t_piece_tetris_simp **pieces);
void							free_pieces(t_piece_tetris_simp **pieces);

#endif
