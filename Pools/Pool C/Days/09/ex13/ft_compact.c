/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:07:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 13:18:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int		res;
	int		index;
	int		j;

	res = 0;
	index = 0;
	while (index < length - res)
	{
		if (tab[index] == 0)
		{
			j = index + 1;
			while (j < length - res)
			{
				tab[j - 1] = tab[j];
				j++;
			}
		}
		else
		{
			index++;
			res++;
		}
	}
	return (res);
}
