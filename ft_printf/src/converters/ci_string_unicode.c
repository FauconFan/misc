/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:36:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 22:05:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string_unicode.h"

static int		ft_wcharlen(wchar_t wchar)
{
	/*
	if (c >= MIN_ONE_BYTE && c <= MAX_ONE_BYTE)
		return (1);
	else if (c >= MIN_TWO_BYTE && c <= MAX_TWO_BYTE)
		return (2);
	else if ((c >= MIN_THREE_BYTE_ONE && c <= MAX_THREE_BYTE_ONE) ||
			(c >= MIN_THREE_BYTE_TWO && c <= MAX_THREE_BYTE_TWO))
		return (3);
	else if ((c >= MIN_FOUR_BYTE_ONE && c <= MAX_FOUR_BYTE_ONE) ||
			(c >= MIN_FOUR_BYTE_TWO && c <= MAX_FOUR_BYTE_TWO))
		return (4);
	return (-1);
	*/
	if (wchar <= 0)
		return (0);
	if (wchar < 0x80)
		return (1);
	else if (wchar < 0x800)
		return (2);
	else if (wchar < 0x200000)
		return (3);
	return (4);
}

static void		fill_string(wchar_t wchar, char *str, int size)
{
	if (size == 1)
		str[0] = wchar;
	else if (size == 2)
	{
		str[0] = ((wchar >> 6) + 0xc0);
		str[1] = ((wchar & 0x3F) + 0x80);
	}
	else if (size == 3)
	{
		str[0] = ((wchar >> 12) + 0xE0);
		str[1] = ((wchar >> 6) + 0x80);
		str[2] = ((wchar & 0x3F) + 0x80);
	}
	else
	{
		str[0] = ((wchar >> 18) + 0xF0);
		str[1] = ((wchar >> 12) + 0x80);
		str[2] = ((wchar >> 6) + 0x80);
		str[3] = ((wchar & 0x3F) + 0x80);
	}
}

void	process_special_char(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	wchar_t		wchar;
	char		*str;
	int			size;

	(void)data;
	wchar = va_arg(va, wchar_t);
	size = ft_wcharlen(wchar);
	str = ft_strnew(size);
	fill_string(wchar, str, size);
	sb_append_special(sb, str, 1, size);
	free(str);
}

void	process_special_string(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	wchar_t		*wstr;
	char		*str;
	int			size_tot;
	int			size;
	int			index;
	int			index2;

	(void)data;
	wstr = va_arg(va, wchar_t *);
	index = 0;
	size = 0;
	size_tot = 0;
	while (wstr[index])
	{
		size_tot += ft_wcharlen(wstr[index]);
		index++;
	}
	index = 0;
	index2 = 0;
	str = ft_strnew(size_tot);
	while (wstr[index])
	{
		size = ft_wcharlen(wstr[index]);
		fill_string(wstr[index], str + index2, size);
		index2 += size;
		index++;
	}
	sb_append_special(sb, str, index, size_tot);
	free(str);
}