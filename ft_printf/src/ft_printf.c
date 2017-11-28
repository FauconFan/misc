/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 12:39:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*treat_sep(
		char *str,
		va_list va,
		t_string_buffer *sb)
{
	t_treat_data	*data;
	char			*tmp;

	if ((data = init_treat_data()) == 0)
		return (0);
	if ((str = set_values_treat_data(++str, data)) == 0)
	{
		free_treat_data(data);
		return (str);
	}
	tmp = treat_data(data, va);
	sb_append_normal(sb, tmp);
	free_treat_data(data);
	return (str);
}

static int		process(
		char *str,
		va_list va,
		char **to_print,
		int *len_to_print)
{
	t_string_buffer		*sb;
	char				*tmp;
	int					pos_first_percent;

	if ((sb = new_string_buffer_normal(ft_strnew(0))) == 0)
		return (-1);
	while ((pos_first_percent = ft_strcpos(str, SEPERATOR)) != -1)
	{
		if ((tmp = ft_strsub(str, 0, pos_first_percent)) == 0)
			return (-1);
		sb_append_normal(sb, tmp);
		str += pos_first_percent;
		free(tmp);
		if ((str = treat_sep(str, va, sb)) == 0)
			return (-1);
	}
	sb_append_normal(sb, str);
	return (build_str(sb, to_print, len_to_print));
}

int				ft_printf(
		const char *restrict format,
		...)
{
	va_list				va;
	t_string_buffer		*sb;
	int					res;
	int					len_to_print;
	char				*to_print;

	va_start(va, format);
	if ((sb = new_string_buffer_normal(ft_strnew(0))) == 0)
		return (-1);
	if ((res = process((char *)format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	free_string_buffer(sb);
	write(1, to_print, len_to_print);
	free(to_print);
	return (res);
}

int				ft_dprintf(
		int fd,
		const char *restrict format,
		...)
{
	va_list				va;
	t_string_buffer		*sb;
	int					res;
	int					len_to_print;
	char				*to_print;

	va_start(va, format);
	if ((sb = new_string_buffer_normal(ft_strnew(0))) == 0)
		return (-1);
	if ((res = process((char *)format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	free_string_buffer(sb);
	write(fd, to_print, len_to_print);
	free(to_print);
	return (res);
}
