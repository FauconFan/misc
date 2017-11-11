/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:24:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat(char **str, va_list va, t_string_buffer *sb)
{
	sb_append(sb, va_arg(va, char *));
	*str = (*str + 2);
}

void			die(char *str)
{
	ft_putendl(str);
	exit(1);
}

int				ft_printf(char *str, ...)
{
	va_list				va;
	t_string_buffer		*sb;
	char				*tmp;
	int					pos_first_percent;

	if ((sb = new_string_buffer()) == 0)
		die(WMALLOC);
	va_start(va, str);
	while ((pos_first_percent = ft_strcpos(str, SEPERATOR)) != -1)
	{
		if ((tmp = ft_strsub(str, 0, pos_first_percent)) == 0)
			die(WMALLOC);
		sb_append(sb, tmp);
		str += pos_first_percent;
		free(tmp);
		treat(&str, va, sb);
	}
	sb_append(sb, str);
	va_end(va);
	sb_print_and_free_all(sb);
	return (0);
}
