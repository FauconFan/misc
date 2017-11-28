/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:29:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 21:20:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGEMENT_H
# define MANAGEMENT_H

# include <stdarg.h>
# include "struct_treat_data.h"
# include "ci_sep.h"
# include "ci_numbers.h"
# include "ci_string_ascii.h"
# include "ci_string_unicode.h"
# include "string_buffer.h"

typedef char *(*t_ptrfunc_firstrep)(va_list va, t_treat_data *data);
typedef char *(*t_ptrfunc_lastrep)(char *tmp, va_list va, t_treat_data *data);

t_ptrfunc_firstrep		get_first_rep_function(int id);
t_ptrfunc_lastrep		adapt_params_function(int id);
void					normal_char(va_list va, t_treat_data *data, t_string_buffer *sb);
void					special_char(va_list va, t_treat_data *data, t_string_buffer *sb);
void					special_string(va_list va, t_treat_data *data, t_string_buffer *sb);
char					*numeri(va_list va, t_treat_data *data);

#endif
