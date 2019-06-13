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

#define HEX_OF(c)	((c) < 10 ? (char)(c) + '0' : (char)c - 10 + 'a')

static void	fill_hex(uint8_t c, char *line)
{
	line[0] = HEX_OF(c / 16);
	line[1] = HEX_OF(c % 16);
}

static void	fill_ascii(uint8_t c, char *line)
{
	if (c >= 32 && c <= 126)
		*line = (char)c;
	else
		*line = '.';
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
		fill_hex(content[i], pre_line + index);
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
		fill_ascii(content[i], post_line + i);
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
