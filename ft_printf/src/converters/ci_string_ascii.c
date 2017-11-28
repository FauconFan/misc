/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:28:12 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 19:35:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string_ascii.h"

char	*get_first_rep_ci_string(va_list va, t_treat_data *data)
{
	char	*res;

	(void)data;
	res = va_arg(va, char *);
	if (res == 0)
		return (ft_strdup("(null)"));
	return (ft_strdup(res));
}

char	*adapt_params_function_ci_string(
	char *tmp, va_list va, t_treat_data *data)
{
	char	*res;
	char	*res2;

	(void)va;
	res = ft_strdup(tmp);
	if (data->precision != -1 && data->precision < (int)ft_strlen(res))
	{
		res2 = ft_strsub(res, 0, data->precision);
		free(res);
		res = res2;
	}
	if (data->gabarit != -1 && data->gabarit > (int)ft_strlen(res))
	{
		res2 = ft_strsetnew(data->gabarit, ' ');
		if (data->minus_flag)
			ft_strncpy(res2, res, ft_strlen(res));
		else
			ft_strncpy(res2 + data->gabarit - ft_strlen(res),
				res, ft_strlen(res));
		free(res);
		res = res2;
	}
	return (res);
}

void	process_normal_char(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	char	*str;
	char	c;
	int		len;

	len = ft_max(1, data->gabarit);
	str = ft_strsetnew(len, (data->zero_flag) ? '0' : ' ');
	c = (char)va_arg(va, int);
	if (data->minus_flag)
		*str = c;
	else
		str[len - 1] = c;
	sb_append_special(sb, str, len, len);
	free(str);
}
