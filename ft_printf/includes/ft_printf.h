/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/29 13:22:43 by fauconfan        ###   ########.fr       */
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

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				ft_sprintf(char **str, const char *restrict format, ...);
int				ft_snprintf(char **str, size_t size, const char *restrict format, ...);

#endif
