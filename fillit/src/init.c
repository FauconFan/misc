/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:55:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 16:55:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/**
 *	Die function if there is an error, often this function is called with ERROR
 *	String constant.
 */
void			die(char *str)
{
	ft_putendl(str);
	exit(1);
}

/**
 *	Check is a couple is in the buffer - map
 */
static int 		is_in_buf(int x, int y)
{
	return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

/**
 *	Count if the cases of a specific (x, y) coords is neared too (beuh)
 */
static int 		number_sides(char *str, int x, int y)
{
	int 	res;
	int 	i;
	int 	j;

	res = 0;
	i = x - 1;
	j = y;
	res += is_in_buf(i, j) && str[5 * i + j] == '#';
	i += 2;
	res += is_in_buf(i, j) && str[5 * i + j] == '#';
	i = x;
	j = y - 1;
	res += is_in_buf(i, j) && str[5 * i + j] == '#';
	j += 2;
	res += is_in_buf(i, j) && str[5 * i + j] == '#';
	return (res);
}

/**
 *	Check if we have exactly 4 members for a piece and if the piece is uniform.
 *	Number of connections is 6 or 8.
 */
static void		check_number(char *str)
{
	int 	compteur_member;
	int 	index[2];
	int 	tmp;

	compteur_member = 0;
	tmp = 0;
	index[0] = 0;
	while (index[0] < 4)
	{
		index[1] = 0;
		while (index[1] < 4)
		{
			if (str[5 * index[0] + index[1]] == '#')
			{
				compteur_member++;
				tmp += number_sides(str, index[0], index[1]);
			}
			index[1]++;
		}
		index[0]++;
	}
	if ((tmp != 6 && tmp != 8) || compteur_member != 4)
		die(ERROR);
}

/**
 *	Read one piece from fd
 *	Check if we have something else than '#' and '.'
 *	Check if we have '\n' every 4 modulo 5 character
 *	Call check_number to check the rest.
 *	
 *	return a string (char *) with 20 characters (+ '\0')
 */
static char		*read_one_piece(int fd)
{
	char	*buf;
	int 	index[2];
	char 	c;

	buf = ft_strnew(20);
	if (read(fd, buf, 20) < 20)
		return (0);
	index[0] = 0;
	while (index[0] < 4)
	{
		index[1] = 0;
		while (index[1] < 4)
		{
			c = buf[5 * index[0] + index[1]];
			if (c != '#' && c != '.')
				die(ERROR);
			index[1]++;
		}
		index[0]++;
		if (buf[5 * index[0] - 1] != '\n')
			die(ERROR);
	}
	check_number(buf);
	return (buf);
}

t_piece_tetris	**init(char *name_file)
{
	int 			fd;
	t_piece_tetris	**pieces;
	char 			c;
	int 			index;

	if ((fd = open(name_file, O_RDONLY)) <= 2)
		die(ERROR);
	pieces = init_pieces();
	pieces[0] = init_piece(read_one_piece(fd));
	index = 1;
	while (read(fd, &c, 1) == 1)
	{
		if (c != '\n')
			die(ERROR);
		pieces[index] = init_piece(read_one_piece(fd));
		index++;
	}
	return (pieces);
}