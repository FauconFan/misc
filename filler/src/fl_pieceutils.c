/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_pieceutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:18:16 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/08 08:08:32 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		load_piece(t_fillerenv *fl_env)
{
	char	*line;
	char	**splited;

	get_next_line(0, &line, fl_env->env_gnl);
	splited = ft_strsplit(line, ' ');
	free_piece(fl_env);
	load_new_piece(fl_env, ft_atoi(splited[2]), ft_atoi(splited[1]));
	free(line);
	free(splited[0]);
	free(splited[1]);
	free(splited[2]);
	free(splited);
}

void		load_new_piece(t_fillerenv *fl_env, size_t size_x, size_t size_y)
{
	t_piece		*p;
	char		**data;
	char		*tmp;
	size_t		index;

	ft_memcheck((p = (t_piece *)malloc(sizeof(t_piece))));
	ft_memcheck((data = (char **)malloc(sizeof(char *) * (size_y))));
	index = 0;
	tmp = ft_strnew(size_x + 1);
	while (index < size_y)
	{
		if (read(0, tmp, size_x + 1) == -1)
			ft_die(strerror(errno));
		tmp[size_x] = '\0';
		data[index] = ft_strdup(tmp);
		index++;
	}
	free(tmp);
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
