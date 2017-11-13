/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_octalx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:51:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 20:03:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_octalx.h"

char	*get_first_rep_ci_octalx(va_list va, t_treat_data *res)
{
	int		value;
	char	*tmp;

	value = va_arg(va, int);
	tmp = 0;
	if (res->converter_id == CI_XMIN)
		tmp = ft_itoa_base(value, HEXALOWER);
	else
		tmp = ft_itoa_base(value, HEXAUPPER);
	return (tmp);
}

char	*adapt_params_function_ci_octalx(
	char *tmp, va_list va, t_treat_data *data)
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
