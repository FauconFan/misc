/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_pieceutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:18:16 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/11 00:19:51 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		load_piece(t_fillerenv *fl_env)
{
	char	*line;
	char	**splited;
	int		x;
	int		y;

	get_next_line(0, &line, fl_env->env_gnl);
	if (fl_verify_loader_piece(line) == FALSE)
	{
		free(line);
		free_env(&fl_env, WRONG_FORMAT);
	}
	splited = ft_strsplit(line, ' ');
	free_piece(fl_env);
	x = ft_atoi(splited[2]);
	y = ft_atoi(splited[1]);
	fl_free_parsed_string(&splited, &line);
	if (x < 0 || y < 0)
		free_env(&fl_env, WRONG_FORMAT);
	load_new_piece(fl_env, (size_t)x, (size_t)y);
}

void		load_new_piece(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	t_piece		*p;
	char		**data;
	size_t		index_y;

	ft_memcheck((p = (t_piece *)malloc(sizeof(t_piece))));
	ft_memcheck((data = (char **)malloc(sizeof(char *) * (size_y))));
	index_y = 0;
	while (index_y < size_y)
	{
		get_next_line(0, data + index_y, fl_env->env_gnl);
		if (fl_verify_each_line_piece(data[index_y], size_x) == FALSE)
		{
			fl_free_tab_strings(&data, index_y);
			free_env(&fl_env, WRONG_FORMAT);
		}
		index_y++;
	}
	p->content = data;
	p->size_x = size_x;
	p->size_y = size_y;
	fl_env->piece = p;
}

void		free_piece(t_fillerenv *fl_env)
{
	t_piece		*piece;
	size_t		index;

	piece = fl_env->piece;
	if (piece != NULL)
	{
		index = 0;
		while (index < piece->size_y)
		{
			free(piece->content[index]);
			index++;
		}
		free(piece->content);
		free(piece);
	}
}

void		print_piece(t_fillerenv *fl_env)
{
	size_t	index;

	if (fl_env->piece != NULL)
	{
		index = 0;
		while (index < fl_env->piece->size_y)
		{
			ft_dprintf(2, "%s\n", fl_env->piece->content[index]);
			index++;
		}
	}
}
