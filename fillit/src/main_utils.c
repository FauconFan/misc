/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:21:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 17:26:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_utils.h"

int 	get_good_size(int number_pieces)
{
	int 	count;

	count = 1;
	while (count * count < 4 * number_pieces)
		count++;
	return (count);
}

int 	get_number_of_pieces(t_piece_tetris **tab)
{
	int 	res;

	res = 0;
	while (tab[res] != 0)
		res++;
	return (res);
}