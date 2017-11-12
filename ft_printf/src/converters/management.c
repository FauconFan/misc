/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:28:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:09:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "management.h"

char	*(* get_first_rep_function(int id))(va_list, t_treat_data *)
{
	if (id == CI_SEP)
		return (get_first_rep_ci_sep);
	return (0);
}

char	*(* adapt_params_function(int id))(char *, va_list, t_treat_data *)
{
	if (id == CI_SEP)
		return (adapt_params_function_ci_sep);
	return (0);
}