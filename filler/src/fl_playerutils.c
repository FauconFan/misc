/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_playerutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:29 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 17:31:43 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool		is_occupied_by_this_player(char c, int playerId)
{
	if (playerId == PLAYER_X)
	{
		return (c == X_MAJ_CASE || c == X_MIN_CASE);
	}
	else if (playerId == PLAYER_O)
	{
		return (c == O_MAJ_CASE || c == O_MIN_CASE);
	}
	return (FALSE);
}
