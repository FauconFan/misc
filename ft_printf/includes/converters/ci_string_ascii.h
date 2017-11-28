/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_ascii.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:29:03 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 19:36:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_STRING_H
# define CI_STRING_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "string_buffer.h"

void	process_normal_char(va_list va, t_treat_data *res, t_string_buffer *sb);

char	*get_first_rep_ci_string(va_list va, t_treat_data *res);
char	*adapt_params_function_ci_string
				(char *tmp, va_list va, t_treat_data *data);

#endif
