/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:50:36 by pavaucha          #+#    #+#             */
/*   Updated: 2017/08/13 10:58:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_just_chiffre(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '1' || argv[i][j] > '9')
					&& argv[i][j] != '.')
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

int		ft_verf_ligne(char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = j + 1;
			while (k < 9)
			{
				if ((argv[i][j] == argv[i][k])
						&& argv[i][j] != '.' && argv[i][k] != '.')
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verf_col(char **argv)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (j < 9)
	{
		i = 1;
		while (i < 9)
		{
			k = i + 1;
			while (k < 9)
			{
				if ((argv[i][j] == argv[k][j])
					&& argv[i][j] != '.' && argv[k][j] != '.')
					return (0);
				k++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_verf_carre_complement(char **argv, int x, int y)
{
	int		i;
	int		j;
	int		limit[2];

	i = (x / 3) * 3;
	j = (y / 3) * 3;
	limit[0] = i + 3;
	limit[1] = j + 3;
	while (i < limit[0])
	{
		j = (y / 3) * 3;
		while (j < limit[1])
		{
			if (i == x && j == y)
			{
				j++;
				continue ;
			}
			if (argv[i][j] == argv[x][y])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verf_carre(char **argv)
{
	int		index[2];

	index[0] = 0;
	while (index[0] < 9)
	{
		index[1] = 0;
		while (index[1] < 9)
		{
			if (argv[index[0]][index[1]] >= '0'
					&& argv[index[0]][index[1]] <= '9')
			{
				if (ft_verf_carre_complement(argv, index[0], index[1]) == 0)
					return (0);
			}
			index[1]++;
		}
		index[0]++;
	}
	return (1);
}
