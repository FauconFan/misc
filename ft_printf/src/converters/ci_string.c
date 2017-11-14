/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:28:12 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/14 23:42:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string.h"

char	*get_first_rep_ci_string(va_list va, t_treat_data *data)
{
	char	*res;

	(void)data;
	res = va_arg(va, char *);
	return (ft_strdup(res));
}


char	*adapt_params_function_ci_string
				(char *tmp, va_list va, t_treat_data *data)
{
	(void)va;
	(void)data;
	return (ft_strdup(tmp));
}