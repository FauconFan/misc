/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_nextmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:20:04 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 18:50:00 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		update_distance(t_fillerenv *fl_env, int x, int y, int playerId, double *res)
{
	size_t		py;
	size_t		px;
	char		actu;
	double		tmp;

	py = 0;
	while (py < fl_env->size_y)
	{
		px = 0;
		while (px < fl_env->size_x)
		{
			actu = fl_env->map[py][px];
			if (actu != EMPTY_CASE && is_occupied_by_this_player(actu, (playerId == 1) + 1))
			{
				tmp = norme(px, py, x, y);
				if (tmp < *res)
				{
					*res = tmp;
				}
			}
			px++;
		}
		py++;
	}
}

static t_bool	handle_each_cara(char c, int playerId, t_bool *bufferPlayer)
{
	if (is_occupied_by_this_player(c, playerId))
	{
		if (*bufferPlayer == TRUE)
			return (FALSE);
		*bufferPlayer = TRUE;
	}
	if (is_occupied_by_this_player(c, (playerId == 1) + 1))
		return (FALSE);
	return (TRUE);
}

static double		is_valid_move(t_fillerenv *fl_env, int dx, int dy, int playerId)
{
	int		X_actu;
	int		Y_actu;
	double	res;
	t_bool	bufferPlayer;

	bufferPlayer = FALSE;
	Y_actu = dy - 1;
	res = (double)(fl_env->size_x + (int)fl_env->size_y);
	while (++Y_actu < dy + (int)fl_env->piece->size_y)
	{
		if (Y_actu < 0 || Y_actu >= (int)fl_env->size_y)
			return (-1);
		X_actu = dx - 1;
		while (++X_actu < dx + (int)fl_env->piece->size_x)
		{
			if (X_actu < 0 || X_actu >= (int)fl_env->size_x)
				return (-1);
			if (fl_env->piece->content[Y_actu - dy][X_actu - dx] != EMPTY_CASE)
			{
				if (handle_each_cara(fl_env->map[Y_actu][X_actu], playerId, &bufferPlayer) == FALSE)
					return (-1);
				update_distance(fl_env, X_actu, Y_actu, playerId, &res);
			}
		}
	}
	return ((bufferPlayer == TRUE) ? res : -1);
}

t_nextmove			*init_nextmove(t_fillerenv *fl_env, int dx, int dy, int playerId)
{
	t_nextmove	*next_move;
	double		score;

	score = is_valid_move(fl_env, dx, dy, playerId);
	if (score < 0)
		return (NULL);
	ft_memcheck((next_move = (t_nextmove *)malloc(sizeof(t_nextmove))));
	next_move->dx = dx;
	next_move->dy = dy;
	next_move->score = score;
	return (next_move);
}

void				describe(t_nextmove *move)
{
	if (move == NULL)
		ft_printf("Empty move\n");
	else
	{
		ft_printf("Move at x:%d y:%d score:%d", move->dx, move->dy, (int)move->score);
	}
}
