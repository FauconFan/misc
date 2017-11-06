/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris_simp.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:32:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/14 10:46:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TETRIS_SIMP_H
# define PIECE_TETRIS_SIMP_H

typedef struct 					s_piece_tetris_simp
{
	char 						id;
	short						x[4];
	short 						y[4];
}								t_piece_tetris_simp;

# include <stdlib.h>
# include "init.h"

# define INIT_ID	'A'
# define SIZE_MAXX	26

t_piece_tetris_simp				*init_piece_simp(char *str);
void 							print_piece_simp(t_piece_tetris_simp *piece);
void							free_piece_simp(t_piece_tetris_simp *piece);


#endif