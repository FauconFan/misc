/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:28:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 14:54:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "management.h"

t_ptrfunc_firstrep	get_first_rep_function(int id)
{
	if (id == CI_SEP)
		return (get_first_rep_ci_sep);
	else if (id == CI_SMIN || id == CI_SMAJ)
		return (get_first_rep_ci_string);
	return (0);
}

t_ptrfunc_lastrep	adapt_params_function(int id)
{
	if (id == CI_SEP)
		return (adapt_params_function_ci_sep);
	else if (id == CI_SMIN || id == CI_SMAJ)
		return (adapt_params_function_ci_string);
	return (0);
}

void	special_char(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	print_special_char(va, data, sb);
}

char				*numeri(va_list va, t_treat_data *data)
{
	return (buildumeri(va, data));
}
