/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:22:24 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 08:11:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_string(char *s)
{
	int		index;

	index = 0;
	while (s[index])
		ft_putchar(s[index++]);
	ft_putchar('\n');
}

void	ft_print_words_tables(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
	{
		print_string(tab[index++]);
	}
}
