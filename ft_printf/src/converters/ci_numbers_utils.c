/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 15:16:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers_utils.h"

static char		*fill_gabarit(char *str, t_treat_data *data)
{
	char	*tmp;

	if (data->gabarit > (int)ft_strlen(str))
	{
		tmp = ft_strsetnew(data->gabarit, (data->zero_flag) ? '0' : ' ');
		if (data->minus_flag)
			ft_strncpy(tmp + 2 * (data->hashtag_flag), str, ft_strlen(str));
		else
			ft_strncpy(tmp + ft_strlen(tmp) - ft_strlen(str), str, ft_strlen(str));
		free(str);
		str = tmp;
	}
	return (str);
}

static char		*build_str_octal_hashtag_flag(char *str, t_treat_data *data)
{
	char	*res;

	res = ft_strsetnew(ft_max(ft_strlen(str) + 2, data->precision), '0');
	res[0] = '0';
	res[1] = (data->converter_id == CI_XMIN) ? 'x' : 'X';
	ft_strncpy(res + ft_strlen(res) - ft_strlen(str), str, ft_strlen(str));
	res = fill_gabarit(res, data);
	return (res);
}

int		check_octal(char *tmp, char **res, t_treat_data *data)
{
	if (data->converter_id == CI_XMIN || data->converter_id == CI_XMAJ)
	{
		if (data->precision == 0 && ft_strcmp(tmp, "0") == 0)
		{
			*res = ft_strdup("");
			*res = fill_gabarit(*res, data);
		}
		else if (data->hashtag_flag)
		{
			*res = build_str_octal_hashtag_flag(tmp, data);
		}
		else
			return (0);
	}
	else if (data->converter_id == CI_OMIN)
	{
		return (0);
	}
	else
		return (0);
	return (1);
}
