/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/29 10:09:46 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	treat the data when a '%' is found
*/

static char		*treat_sep(
		char *str,
		va_list va,
		t_string_buffer *sb)
{
	t_treat_data	*data;

	if ((data = init_treat_data()) == 0)
		return (0);
	if ((str = set_values_treat_data(++str, data)) == 0)
	{
		free_treat_data(data);
		return (str);
	}
	treat_data(data, va, sb);
	free_treat_data(data);
	return (str);
}

/*
**	parse the data properly. It use string buffer
*/

static int		process(
		char *str,
		va_list va,
		t_string_buffer *sb,
		char **to_print,
		int *len_to_print)
{
	char				*tmp;
	int					pos_first_percent;

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

/*
**	ft_printf...
*/

int				ft_printf(
		const char *restrict format,
		...)
{
	va_list				va;
	t_string_buffer		*sb;
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((sb = new_string_buffer_normal("")) == 0)
		return (-1);
	if ((res = process((char *)format, va, sb, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	free_string_buffer(sb);
	write(1, to_print, len_to_print);
	free(to_print);
	return (res);
}

/*
**	ft_dprintf...
*/

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

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((sb = new_string_buffer_normal("")) == 0)
		return (-1);
	if ((res = process((char *)format, va, sb, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	free_string_buffer(sb);
	write(fd, to_print, len_to_print);
	free(to_print);
	return (res);
}
