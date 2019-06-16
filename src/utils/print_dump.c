/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 07:59:12 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static char	hex_of(char c)
{
	if (c < 10)
		return (c + '0');
	return (c - 10 + 'a');
}

static void	fill_preline(uint8_t *content, size_t len, char pre_line[50])
{
	size_t	i;
	size_t	index;

	pre_line[49] = 0;
	i = 0;
	index = 0;
	while (i < 16 && i < len)
	{
		pre_line[index] = hex_of(content[i] / 16);
		pre_line[index + 1] = hex_of(content[i] % 16);
		index += 2;
		pre_line[index++] = ' ';
		if (i == 7)
			pre_line[index++] = ' ';
		++i;
	}
	while (index < 49)
		pre_line[index++] = ' ';
}

static void	fill_postline(uint8_t *content, size_t len, char post_line[17])
{
	size_t	i;

	i = 0;
	while (i < 16 && i < len)
	{
		if (content[i] >= 32 && content[i] <= 126)
			post_line[i] = (char)content[i];
		else
			post_line[i] = '.';
		++i;
	}
	post_line[i] = 0;
}

void		print_dump(uint8_t *content, size_t len)
{
	char	pre_line[50];
	char	post_line[17];

	if (len == 0)
		return ;
	fill_preline(content, len, pre_line);
	fill_postline(content, len, post_line);
	ft_put_str("\t\t");
	ft_put_str(pre_line);
	ft_put_str("  |");
	ft_put_str(post_line);
	ft_put_str_ln("|");
	if (len > 16)
		print_dump(content + 16, len - 16);
}
