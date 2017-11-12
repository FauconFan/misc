/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str_treat_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:41:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:10:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_str_treat_data.h"

char			*get_first_rep(va_list va, t_treat_data *data)
{
	return ((get_first_rep_function(data->converter_id))(va, data));
}

char			*adapt_flags_gabarit_precision
		(char *tmp, va_list va, t_treat_data *data)
{
	char	*res;

	res = ((adapt_params_function(data->converter_id))(tmp, va, data));
	free(tmp);
	return (res);
}