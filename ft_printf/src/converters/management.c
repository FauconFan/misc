/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:28:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/14 23:33:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "management.h"

static int			is_numeri(int id)
{
	return (id >= 13 && id <= 21);
}

t_ptrfunc_firstrep	get_first_rep_function(int id)
{
	if (id == CI_SEP)
		return (get_first_rep_ci_sep);
	else if (is_numeri(id))
		return (get_first_rep_ci_numbers);
	else if (id == CI_SMIN || id == CI_SMAJ)
		return (get_first_rep_ci_string);
	return (0);
}

t_ptrfunc_lastrep	adapt_params_function(int id)
{
	if (id == CI_SEP)
		return (adapt_params_function_ci_sep);
	else if (is_numeri(id))
		return (adapt_params_function_ci_numbers);
	else if (id == CI_SMIN || id == CI_SMAJ)
		return (adapt_params_function_ci_string);
	return (0);
}
