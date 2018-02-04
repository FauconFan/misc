/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:19:42 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 19:37:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int			main(void)
{
	t_fillerenv		*fl_env;
	t_nextmove		*move;

	fl_env = init_env();
	load_player(fl_env);
	while (1)
	{
		load_map(fl_env);
		load_piece(fl_env);
		adapt_strategy(fl_env);
		move = find_nextmove(fl_env);
		describe(move);
		if (move == NULL)
			break ;
		free(move);
	}
	free_env(&fl_env);
	return (0);
}
