/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_playerutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:29 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/10 12:35:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool		is_occupied_by_this_player(char c, t_bool player_id)
{
	if (player_id)
	{
		return (c == O_CASE);
	}
	return (c == X_CASE);
}

t_bool		occ_opp(t_fillerenv *fl_env, int y, int x)
{
	return (is_occupied_by_this_player(fl_env->map[y][x],
						fl_env->opposite_player));
}

void		load_player(t_fillerenv *fl_env)
{
	char		*line;

	get_next_line(0, &line, fl_env->env_gnl);
	fl_env->is_first_player = (ft_strstr(line, "p1") != NULL);
	fl_env->opposite_player = (fl_env->is_first_player == FALSE);
	free(line);
}

int			inverse_player(t_bool p)
{
	return (p == FALSE);
}
