/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tetris_simp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:32:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/11 13:15:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece_tetris_simp.h"

static t_piece_tetris_simp		*new_piece_simp()
{
	static char 			count_id = INIT_ID;

	t_piece_tetris_simp		*res;
	if ((res = (t_piece_tetris_simp *)malloc(sizeof(t_piece_tetris_simp))) == NULL)
		die("Wrong malloc !");
	res->id = count_id;
	count_id++;
	return (res);
}

static void 					setValues(t_piece_tetris_simp *res, char *str)
{
	short 	i;
	short 	j;
	int 	compteur;

	i = 0;
	compteur = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[5 * i + j] == '#')
			{
				res->x[compteur] = i;
				res->y[compteur] = j;
				compteur++;
				if (compteur == 4)
					return ;
			}
			j++;
		}
		i++;
	}
}

static void 					simplifyValues(t_piece_tetris_simp *res)
{
	while (res->x[0] != 0 && res->x[1] != 0 && res->x[2] != 0 && res->x[3] != 0)
	{
		res->x[0] = res->x[0] - 1;
		res->x[1] = res->x[1] - 1;
		res->x[2] = res->x[2] - 1;
		res->x[3] = res->x[3] - 1;
	}
	while (res->y[0] != 0 && res->y[1] != 0 && res->y[2] != 0 && res->y[3] != 0)
	{
		res->y[0] = res->y[0] - 1;
		res->y[1] = res->y[1] - 1;
		res->y[2] = res->y[2] - 1;
		res->y[3] = res->y[3] - 1;
	}
}

t_piece_tetris_simp				*init_piece_simp(char *str)
{
	t_piece_tetris_simp		*res;

	res = new_piece_simp();
	setValues(res, str);
	simplifyValues(res);
	free(str);
	return (res);
}

void 							print_piece_simp(t_piece_tetris_simp *piece)
{
	int 		index;

	ft_putstr("[ ");
	index = 0;
	while (index < 4)
	{
		ft_putstr("(");
		ft_putnbr(piece->x[index]);
		ft_putstr(", ");
		ft_putnbr(piece->y[index]);
		ft_putstr(") ");
		index++;
	}
	ft_putstr("]");
}

void							free_piece_simp(t_piece_tetris_simp *piece)
{
	free(piece);
}