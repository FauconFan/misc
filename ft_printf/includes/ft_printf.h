/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:35:48 by fauconfan         #+#    #+#             */
/*   Updated: 2017/11/30 17:37:18 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <locale.h>
# include "libft.h"
# include "treat_data_utils.h"
# include "string_buffer.h"
# include "string_buffer_utils.h"

int				ft_center_printf(const char *restrict format, va_list va,
						char **answer, int *len_to_print);

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				ft_sprintf(char **str, const char *restrict format, ...);
int				ft_snprintf(char **str, size_t size,
						const char *restrict format, ...);

int				ft_vprintf(const char *restrict format, va_list ap);
int				ft_vdprintf(int fd, const char *restrict format, va_list ap);
int				ft_vsprintf(char **str,
						const char *restrict format, va_list ap);
int				ft_vsnprintf(char **str, size_t size,
						const char *restrict format, va_list ap);

#endif
