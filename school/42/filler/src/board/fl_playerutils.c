/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_playerutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:29 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/10 22:21:43 by fauconfan        ###   ########.fr       */
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
	t_bool		p1;
	t_bool		p2;

	get_next_line(0, &line, fl_env->env_gnl);
	p1 = (ft_strstr(line, "p1 ") != NULL);
	p2 = (ft_strstr(line, "p2 ") != NULL);
	if (fl_verify_loader_player(line) == FALSE ||
			((p1 ^ p2) == FALSE))
	{
		free(line);
		free_env(&fl_env, WRONG_FORMAT);
	}
	fl_env->is_first_player = p1;
	fl_env->opposite_player = p2;
	free(line);
}

int			inverse_player(t_bool p)
{
	return (p == FALSE);
}
