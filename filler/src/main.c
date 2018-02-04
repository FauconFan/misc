/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:19:42 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 19:37:45 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int			main(void)
{
	t_fillerenv		*fl_env;

	fl_env = init_env();
	load_new_map(fl_env, 17, 15);
	load_piece(fl_env, 2, 2);
	print_map(fl_env);
	print_piece(fl_env);

	t_nextmove	*test;

	test = find_nextmove(fl_env, PLAYER_O);
	describe(test);


	free_env(&fl_env);
	return(0);
}
