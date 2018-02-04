/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_playerutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:29 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 19:18:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool		is_occupied_by_this_player(char c, int player_id)
{
	if (player_id == PLAYER_X)
	{
		return (c == X_MAJ_CASE || c == X_MIN_CASE);
	}
	else if (player_id == PLAYER_O)
	{
		return (c == O_MAJ_CASE || c == O_MIN_CASE);
	}
	return (FALSE);
}

void		load_player(t_fillerenv *fl_env)
{
	char		*line;

	get_next_line(0, &line, fl_env->env_gnl);
	if (strstr(line, "p1") != NULL)
	{
		fl_env->ai_id = PLAYER_O;
	}
	else
	{
		fl_env->ai_id = PLAYER_X;
	}
	free(line);
}

int			inverse_player(int p)
{
	return ((p == 1) + 1);
}
