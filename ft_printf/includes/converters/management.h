/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:29:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 19:45:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGEMENT_H
# define MANAGEMENT_H

# include <stdarg.h>
# include "struct_treat_data.h"
# include "ci_sep.h"

typedef char *(*t_ptrfunc_firstrep)(va_list va, t_treat_data *data);
typedef char *(*t_ptrfunc_lastrep)(char *tmp, va_list va, t_treat_data *data);

t_ptrfunc_firstrep		get_first_rep_function(int id);
t_ptrfunc_lastrep		adapt_params_function(int id);

#endif
