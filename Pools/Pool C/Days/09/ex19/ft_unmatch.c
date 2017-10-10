/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:47:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 15:01:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		index[2];
	int		is_number;

	index[0] = 0;
	while (index[0] < length)
	{
		index[1] = 0;
		is_number = 1;
		while (index[1] < length)
		{
			if (index[0] == index[1])
			{
				index[1]++;
				continue ;
			}
			if (tab[index[0]] == tab[index[1]])
				is_number = 0;
			index[1]++;
		}
		if (is_number == 1)
			return (tab[index[0]]);
		index[0]++;
	}
	return (0);
}
