/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:11:14 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 14:12:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		min_rank;
	char	*min_str;
	int		index;

	if (*tab == 0)
		return ;
	min_rank = 0;
	min_str = *tab;
	index = 1;
	while (tab[index])
	{
		if (cmp(tab[index], min_str) < 0)
		{
			min_str = tab[index];
			min_rank = index;
		}
		index++;
	}
	tab[min_rank] = tab[0];
	tab[0] = min_str;
	ft_advanced_sort_wordtab(tab + 1, cmp);
}
