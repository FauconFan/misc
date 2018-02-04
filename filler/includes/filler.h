/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:19:51 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/03 18:46:37 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define EMPTY_CASE			'.'
# define X_MAJ_CASE			'X'
# define X_MIN_CASE			'x'
# define O_MAJ_CASE			'O'
# define O_MIN_CASE			'o'

# define PLAYER_X			1
# define PLAYER_O			2

# define PRECISION_SQRT		0.00001

typedef struct		s_piece
{
	char	**content;
	size_t	size_x;
	size_t	size_y;
}					t_piece;

typedef struct		s_nextmove
{
	int			dx;
	int			dy;
	double		score;
}					t_nextmove;

typedef struct		s_fillerenv
{
	char		**map;
	size_t		size_x;
	size_t		size_y;
	t_piece		*piece;
	int			ai_id;
	t_env_gnl	*env_gnl;
}					t_fillerenv;

/*
**	fl_envutils.c
*/

t_fillerenv			*init_env(void);
void				free_env(t_fillerenv **fl_env);

/*
**	fl_pieceutils.c
*/

void				load_piece(t_fillerenv *fl_env, size_t size_x, size_t size_y);
void				free_piece(t_fillerenv *fl_env);
void				print_piece(t_fillerenv *fl_env);

/*
**	fl_maputils.c
*/

void				load_new_map(t_fillerenv *fl_env, size_t size_x, size_t size_y);
void				free_map(t_fillerenv *fl_env);
void				print_map(t_fillerenv *fl_env);

/*
**	fl_nextmove.c
*/

t_nextmove			*init_nextmove(t_fillerenv *fl_env, int dx, int dy, int playerId);
void				describe(t_nextmove *move);

/*
**	fl_algo_findbestmove.c
*/

t_nextmove			*find_nextmove(t_fillerenv *fl_env, int playerId);

/*
**	fl_playerutils.c
*/

t_bool				is_occupied_by_this_player(char c, int playerId);

/*
**	fl_math.c
*/

double				norme(int x1, int y1, int x2, int y2);
double				my_sqrt(double n);

#endif