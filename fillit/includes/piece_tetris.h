/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:11:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 12:20:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TETRIS_H
# define PIECE_TETRIS_H

# define INIT_ID	'A'

typedef struct 					s_piece_tetris
{
	char 						id;
	char 						**rep;
}								t_piece_tetris;

t_piece_tetris	*init_piece(char *str);
void 			print_piece(t_piece_tetris *piece);
void			free_piece(t_piece_tetris *piece);

#endif