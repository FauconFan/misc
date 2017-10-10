/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:29:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 13:47:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"
#include "grid.h"

void	init_values_resultat(t_grid *grid, int nb_line, char *entry)
{
	grid->height = nb_line;
	grid->length = 0;
	while (entry[grid->length + 4] != '\n')
		grid->length += 1;
}

t_grid	*entry_build(char *entry, int nb_line)
{
	int		**res;
	t_grid	*resultat;
	int		index[3];

	if ((resultat = (t_grid *)malloc(sizeof(t_grid))) == NULL)
		return (0);
	if ((res = (int **)malloc(sizeof(int *) * nb_line)) == NULL)
		return (0);
	init_values_resultat(resultat, nb_line, entry);
	index[0] = 0;
	index[1] = 4;
	while (index[0] < nb_line)
	{
		index[2] = 0;
		res[index[0]] = (int *)malloc(sizeof(int) * resultat->length);
		if (res[index[0]] == NULL)
			return (0);
		while (entry[index[1]] != 0 && index[2] != resultat->length)
			res[index[0]][index[2]++] = (entry[index[1]++] == *entry) ? -1 : 0;
		index[1]++;
		index[0]++;
	}
	resultat->tab = res;
	return (resultat);
}

t_grid	*entry_test_and_build(char *entry)
{
	int		nb_line;

	if ((nb_line = check_first_line(&entry)) == -1)
		return (0);
	if (ft_strlen(entry) <= 4)
		return (0);
	if (check_lines(entry, nb_line) == -1)
		return (0);
	return (entry_build(entry, nb_line));
}

void	free_grid(t_grid *res)
{
	int		index;

	index = 0;
	while (index < res->height)
	{
		free(res->tab[index]);
		index++;
	}
	free(res->tab);
	free(res);
}
