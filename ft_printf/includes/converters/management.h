/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:29:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 09:20:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGEMENT_H
# define MANAGEMENT_H

# include <stdarg.h>
# include "struct_treat_data.h"
# include "ci_sep.h"
# include "ci_numbers.h"
# include "ci_string.h"
# include "ci_character.h"

typedef char *(*t_ptrfunc_firstrep)(va_list va, t_treat_data *data);
typedef char *(*t_ptrfunc_lastrep)(char *tmp, va_list va, t_treat_data *data);

t_ptrfunc_firstrep		get_first_rep_function(int id);
t_ptrfunc_lastrep		adapt_params_function(int id);
void					special_char(
		va_list va, t_treat_data *data);
char					*numeri(va_list va, t_treat_data *data);

#endif
