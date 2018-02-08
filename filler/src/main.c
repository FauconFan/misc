/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:19:42 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/08 08:29:23 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void		describe_move(t_nextmove *move)
{
	if (move == NULL)
		ft_dprintf(1, "Empty move\n");
	else
	{
		ft_dprintf(1, "%d %d\n", move->dy, move->dx);
	}
}

int				main(void)
{
	t_fillerenv		*fl_env;
	t_nextmove		*move;

	fl_env = init_env();
	load_player(fl_env);
	while (1)
	{
		load_map(fl_env);
		load_piece(fl_env);
		free_list_opposite(fl_env);
		calculate_list_opponent(fl_env);
		adapt_strategy(fl_env);
		move = find_nextmove(fl_env);
		describe_move(move);
		if (move == NULL)
			break ;
		free(move);
	}
	free_env(&fl_env);
	return (0);
}
