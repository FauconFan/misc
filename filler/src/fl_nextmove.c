/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_nextmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:20:04 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/04 20:00:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		update_distance(t_fillerenv *fl_env, int x, int y, double *res)
{
	size_t		py;
	size_t		px;
	char		actu;
	double		tmp;

	py = 0;
	while (++py < fl_env->size_y)
	{
		px = 0;
		while (++px < fl_env->size_x)
		{
			actu = fl_env->map[py][px];
			if (actu != EMPTY_CASE && is_occupied_by_this_player(actu,
						inverse_player(fl_env->ai_id)))
			{
				if (fl_env->mode == NOT_SET || fl_env->mode == DEFAULT_MODE)
					tmp = norme(px, py, x, y);
				else
					tmp = norme(x, y, x,
						(fl_env->mode == HIGHWAY_TO_HELL) * fl_env->size_y);
				if (tmp < *res)
					*res = tmp;
			}
		}
	}
}

static t_bool	handle_each_cara(char c, int player_id, t_bool *buffer_player)
{
	if (is_occupied_by_this_player(c, player_id))
	{
		if (*buffer_player == TRUE)
			return (FALSE);
		*buffer_player = TRUE;
	}
	if (is_occupied_by_this_player(c, inverse_player(player_id)))
		return (FALSE);
	return (TRUE);
}

static t_bool	is_valid_move(t_fillerenv *fl_env, int dx, int dy,
						double *score)
{
	int		x_actu;
	int		y_actu;
	t_bool	buffer_player;

	buffer_player = FALSE;
	y_actu = dy - 1;
	while (++y_actu < dy + (int)fl_env->piece->size_y)
	{
		if (y_actu < 0 || y_actu >= (int)fl_env->size_y)
			return (FALSE);
		x_actu = dx - 1;
		while (++x_actu < dx + (int)fl_env->piece->size_x)
		{
			if (x_actu < 0 || x_actu >= (int)fl_env->size_x)
				return (FALSE);
			if (fl_env->piece->content[y_actu - dy][x_actu - dx] != EMPTY_CASE)
			{
				if (handle_each_cara(fl_env->map[y_actu][x_actu],
							fl_env->ai_id, &buffer_player) == FALSE)
					return (FALSE);
				update_distance(fl_env, x_actu, y_actu, score);
			}
		}
	}
	return (buffer_player);
}

t_nextmove		*init_nextmove(t_fillerenv *fl_env, int dx, int dy)
{
	t_nextmove	*next_move;
	double		score;

	score = (double)(fl_env->size_x + (int)fl_env->size_y);
	if (is_valid_move(fl_env, dx, dy, &score) == FALSE)
		return (NULL);
	ft_memcheck((next_move = (t_nextmove *)malloc(sizeof(t_nextmove))));
	next_move->dx = dx;
	next_move->dy = dy;
	next_move->score = score;
	return (next_move);
}

void			describe(t_nextmove *move)
{
	if (move == NULL)
		ft_dprintf(1, "Empty move\n");
	else
	{
		ft_dprintf(1, "%d %d\n", move->dy, move->dx);
	}
}
