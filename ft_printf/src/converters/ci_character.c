/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:27:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 14:01:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_character.h"

char	*get_first_rep_ci_char(va_list va, t_treat_data *data)
{
	char	*res;

	(void)data;
	res = ft_strdup("_");
	res[0] = (char)va_arg(va, int);
	return (res);
}


char	*adapt_params_function_ci_char
				(char *tmp, va_list va, t_treat_data *data)
{
	(void)va;
	(void)data;
	return (ft_strdup(tmp));
}
