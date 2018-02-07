/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:19:51 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/07 15:37:33 by fauconfan        ###   ########.fr       */
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

# define O_CASE				'1'
# define X_CASE				'2'

# define PRECISION_SQRT		0.00001

# define NOT_SET			-42
# define DEFAULT_MODE		0
# define HIGHWAY_TO_HELL	-1
# define HIGHWAY_TO_SKY		1

/*
**	Mode Calculus d
**	1 => Euclidean distance
**	2 => Manhattan distance
**	Default Euclidean
*/

# define MODE_EUCLIDEAN		1
# define MODE_MANHATTAN		2

# define MODE_CALCULUS_D	2

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

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
	t_bool		is_first_player;
	t_bool		opposite_player;
	t_env_gnl	*env_gnl;
	int			mode;
	t_list		*list_oppositecases;
}					t_fillerenv;

/*
**	fl_envutils.c
*/

t_fillerenv			*init_env(void);
void				free_env(t_fillerenv **fl_env);

/*
**	fl_pieceutils.c
*/

void				load_piece(t_fillerenv *fl_env);
void				load_new_piece(t_fillerenv *fl_env,
						size_t size_x, size_t size_y);
void				free_piece(t_fillerenv *fl_env);
void				print_piece(t_fillerenv *fl_env);

/*
**	fl_maputils.c
*/

void				load_map(t_fillerenv *fl_env);
void				load_new_map(t_fillerenv *fl_env,
						size_t size_x, size_t size_y);
void				free_map(t_fillerenv *fl_env);
void				print_map(t_fillerenv *fl_env);

/*
**	fl_nextmove.c
*/

t_nextmove			*init_nextmove(t_fillerenv *fl_env, int dx, int dy);

/*
**	fl_algo_findbestmove.c
*/

t_nextmove			*find_nextmove(t_fillerenv *fl_env);

/*
**	fl_adapt_strategy.c
*/

void				adapt_strategy(t_fillerenv *fl_env);

/*
**	fl_playerutils.c
*/

t_bool				is_occupied_by_this_player(char c, t_bool player_id);
void				load_player(t_fillerenv *fl_env);
int					inverse_player(t_bool p);
t_bool				occ_opp(t_fillerenv *fl_env, int y, int x);

/*
**	fl_math.c
*/

double				norme(int x1, int y1, int x2, int y2);

/*
**	fl_storeoppositecases.c
*/

void				free_list_opposite(t_fillerenv *fl_env);
void				store_one_point(t_fillerenv *fl_env, int x, int y);
void				simple_display(void *content);
void				calculate_list_opponent(t_fillerenv *fl_env);

#endif
