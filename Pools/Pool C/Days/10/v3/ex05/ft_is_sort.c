/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:28:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 13:12:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort_croissant(int *tab, int length, int (*f)(int, int))
{
	int		index;

	index = 0;
	while (index < length - 1)
	{
		if (f(*tab, *(tab + 1)) > 0)
			return (0);
		tab++;
		index++;
	}
	return (1);
}

int		ft_is_sort_decroissant(int *tab, int length, int (*f)(int, int))
{
	int		index;

	index = 0;
	while (index < length - 1)
	{
		if (f(*tab, *(tab + 1)) < 0)
			return (0);
		tab++;
		index++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		mode;
	int		index;

	mode = 0;
	index = 0;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) != 0)
		{
			if (f(tab[index], tab[index + 1]) > 0)
			{
				mode = 1;
				break ;
			}
			mode = -1;
			break ;
		}
		index++;
	}
	if (mode == 0)
		return (1);
	if (mode == -1)
		return (ft_is_sort_croissant(tab, length, f));
	return (ft_is_sort_decroissant(tab, length, f));
}
