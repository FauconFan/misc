/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:56:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:45:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_sep.h"

char	*get_first_rep_ci_sep(va_list va, t_treat_data *res)
{
	(void)va;
	(void)res;
	return (ft_strdup("%"));
}

char	*adapt_params_function_ci_sep(char *tmp, va_list va, t_treat_data *data)
{
	char	*res;
	int		len;

	(void)va;
	len = ft_max(data->gabarit, ft_strlen(tmp));
	res = ft_strsetnew(len, ' ');
	if (data->minus_flag)
		ft_strncpy(res, tmp, ft_strlen(tmp));
	else
		ft_strncpy(res + len - ft_strlen(tmp), tmp, ft_strlen(tmp));
	return (res);
}
