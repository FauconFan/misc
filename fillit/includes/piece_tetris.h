/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 18:34:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TETRIS_H
# define PIECE_TETRIS_H

typedef struct 					s_piece_tetris
{
	char 						id;
	char 						**rep;
}								t_piece_tetris;

# include <stdlib.h>
# include "piece_tetris_utils.h"
# include "init.h"
# include "libft.h"

# define INIT_ID	'A'
# define SIZE_MAX	26

t_piece_tetris	*init_piece(char *str);
void 			print_piece(t_piece_tetris *piece);
void			free_piece(t_piece_tetris *piece);

#endif