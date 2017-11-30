/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:28:12 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 11:54:24 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string_ascii.h"

void	process_normal_string(va_list va, t_treat_data *data, t_string_buffer *sb)
{
	char	*res;
	char	*tmp;

	tmp = va_arg(va, char *);
	if (tmp == 0)
		tmp = "(null)";
	res = ft_strdup(tmp);
	if (data->precision != -1 && data->precision < (int)ft_strlen(res))
	{
		tmp = ft_strsub(res, 0, data->precision);
		free(res);
		res = tmp;
	}
	if (data->gabarit > (int)ft_strlen(res))
	{
		tmp = ft_strsetnew(data->gabarit, ' ');
		if (data->minus_flag)
			ft_strncpy(tmp, res, ft_strlen(res));
		else
			ft_strncpy(tmp + data->gabarit - ft_strlen(res),
				res, ft_strlen(res));
		free(res);
		res = tmp;
	}
	sb_append_normal(sb, res);
	free(res);
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
