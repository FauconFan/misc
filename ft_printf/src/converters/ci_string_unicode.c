/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:36:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 19:53:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string_unicode.h"

int		ft_wcharlen(unsigned int c)
{
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
}

void	process_special_char(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	wchar_t	cara;

	(void)data;
	(void)sb;
	cara = va_arg(va, wchar_t);
	ft_putchar((char)(cara >> 16));
	ft_putchar((char)(cara >> 8));
	ft_putchar((char)(cara));
}
