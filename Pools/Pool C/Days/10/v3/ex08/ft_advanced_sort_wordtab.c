/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:11:14 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 13:20:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		length;

	j = 0;
	length = 0;
	while (tab[length])
		length++;
	while (j < length)
	{
		i = 0;
		while (tab[i + 1])
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
				swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
