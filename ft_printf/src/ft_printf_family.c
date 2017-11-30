/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_family.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:29 by fauconfan         #+#    #+#             */
/*   Updated: 2017/11/30 17:39:56 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_center_printf(const char *restrict format, va_list va,
					char **answer, int *len_to_print)
{
	t_string_buffer		*sb;
	int					res;
	int					tampon;

	setlocale(LC_ALL, "");
	if ((sb = new_string_buffer_normal("")) == 0)
		return (-1);
	if ((res = process((char *)format, va, sb, answer, &tampon)) == -1)
		return (-1);
	free_string_buffer(sb);
	if (len_to_print != 0)
		*len_to_print = tampon;
	return (res);
}

/*
**	ft_printf...
*/

int				ft_printf(const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	write(1, to_print, len_to_print);
	free(to_print);
	return (res);
}

/*
**	ft_dprintf...
*/

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	write(fd, to_print, len_to_print);
	free(to_print);
	return (res);
}

/*
**	ft_sprintf
*/

int				ft_sprintf(char **str, const char *restrict format, ...)
{
	va_list				va;
	int					res;
	char				*to_print;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, 0)) == -1)
		return (-1);
	va_end(va);
	*str = to_print;
	return (res);
}

/*
**	ft_snprintf
**	can have some bugs with unicode...
*/

int				ft_snprintf(char **str, size_t size,
					const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;
	int					len;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	len = ft_min(size, len_to_print);
	*str = ft_strnew(len);
	ft_strncpy(*str, to_print, len);
	return (res);
}
