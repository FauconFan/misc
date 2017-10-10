/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:46:53 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 14:07:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_wordtab(char **tab)
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
		if (my_strcmp(tab[index], min_str) < 0)
		{
			min_str = tab[index];
			min_rank = index;
		}
		index++;
	}
	tab[min_rank] = tab[0];
	tab[0] = min_str;
	ft_sort_wordtab(tab + 1);
}
