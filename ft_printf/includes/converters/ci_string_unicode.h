/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:32:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 17:36:07 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_STRING_UNICODE_H
# define CI_STRING_UNICODE_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "string_buffer.h"

void	process_special_char(va_list va, t_treat_data *data,
					t_string_buffer *sb);
void	process_special_string(va_list va, t_treat_data *data,
					t_string_buffer *sb);

#endif
