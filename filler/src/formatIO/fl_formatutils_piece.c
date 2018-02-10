/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_formatutils_piece.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 00:01:58 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/11 00:21:09 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool		fl_verify_each_line_piece(char *str, size_t x)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != FULL_PIECE_CASE && str[index] != EMPTY_CASE)
			return (FALSE);
		index++;
	}
	if (index != x)
		return (FALSE);
	return (TRUE);
}
