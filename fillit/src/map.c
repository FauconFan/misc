/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:06:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 18:01:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(int size)
{
	t_map	*res;
	int		index[2];

	if ((res = (t_map *)malloc(sizeof(t_map))) == NULL)
		die("Wrong Malloc !");
	res->size = size;
	if ((res->map = (char **)malloc(sizeof(char *) * size)) == NULL)
		die("Wrong Malloc !");
	index[0] = 0;
	while (index[0] < size)
	{
		res->map[index[0]] = ft_strnew(size);
		index[1] = 0;
		while (index[1] < size)
		{
			res->map[index[0]][index[1]] = '.';
			index[1]++;
		}
		index[0]++;
	}
	return (res);
}

void	print_map(t_map *map)
{
	int		index;

	index = 0;
	while (index < map->size)
	{
		ft_putendl(map->map[index]);
		index++;
	}
}

void	free_map(t_map *map)
{
	int		index;

	index = 0;
	while (index < map->size)
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
	free(map);
}
