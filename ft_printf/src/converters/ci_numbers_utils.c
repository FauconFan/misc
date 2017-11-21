/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:56:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers_utils.h"

static long long			get_rep_no_unsigned(va_list va, t_treat_data *data)
{
	if (data->length_modifier_id != -1)
	{
		if (data->length_modifier_id == LM_HH)
			return ((long long)((char)va_arg(va, int)));
		else if (data->length_modifier_id == LM_H)
			return ((long long)((short)va_arg(va, int)));
		else if (data->length_modifier_id == LM_L)
			return ((long long)va_arg(va, long));
		else if (data->length_modifier_id == LM_LL)
			return ((long long)va_arg(va, long long));
		else if (data->length_modifier_id == LM_J)
			return ((long long)va_arg(va, intmax_t));
		else if (data->length_modifier_id == LM_Z)
			return ((long long)va_arg(va, size_t));
	}
	if (data->converter_id == CI_DMIN || data->converter_id == CI_I)
		return ((long long)va_arg(va, int));
	return ((long long)va_arg(va, long int));
}

static unsigned long long	get_rep_unsigned(va_list va, t_treat_data *data)
{
	if (data->length_modifier_id != -1)
	{
		if (data->length_modifier_id == LM_HH)
			return ((unsigned long long)
				((unsigned char)va_arg(va, unsigned int)));
		else if (data->length_modifier_id == LM_H)
			return ((unsigned long long)
				((unsigned short)va_arg(va, unsigned int)));
		else if (data->length_modifier_id == LM_L)
			return ((unsigned long long)va_arg(va, unsigned long));
		else if (data->length_modifier_id == LM_LL)
			return ((unsigned long long)va_arg(va, unsigned long long));
		else if (data->length_modifier_id == LM_J)
			return ((unsigned long long)va_arg(va, uintmax_t));
		else if (data->length_modifier_id == LM_Z)
			return ((unsigned long long)va_arg(va, size_t));
	}
	return ((unsigned long long)va_arg(va, unsigned int));
}

static char					*get_first_rep_ci_numbers(
								va_list va, t_treat_data *res)
{
	if (res->converter_id == CI_DMIN || res->converter_id == CI_I)
		return (ft_lltoa_base(get_rep_no_unsigned(va, res), BASE_DECA));
	else if (res->converter_id == CI_OMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_OCTO));
	else if (res->converter_id == CI_UMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_DECA));
	else if (res->converter_id == CI_XMIN || res->converter_id == CI_P)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_HEXAMIN));
	else if (res->converter_id == CI_XMAJ)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_HEXAMAJ));
	return (ft_strnew(0));
}

char						*get_rep_with_prec(va_list va, t_treat_data *data)
{
	char	*str;
	char	*tmp;

	str = get_first_rep_ci_numbers(va, data);
	if (data->precision + (*str == '-') > (int)ft_strlen(str))
	{
		if (*str != '-')
		{
			tmp = ft_strsetnew(data->precision, '0');
			ft_strncpy(tmp + data->precision - ft_strlen(str), str, ft_strlen(str));
		}
		else
		{
			tmp = ft_strsetnew(data->precision + 1, '0');
			ft_strncpy(tmp + data->precision + 2 - ft_strlen(str), str + 1, ft_strlen(str) - 1);
			*tmp = '-';
		}
		free(str);
		str = tmp;
	}
	else if (data->precision == 0 && ft_strcmp(ZERO_SOLO, str) == 0)
	{
		free(str);
		str = ft_strnew(1);
	}
	return (str);
}

char						*get_prefix(char **str, t_treat_data *data)
{
	char	*tmp;

	if (**str == '-')
	{
		tmp = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		free(*str);
		*str = tmp;
		return (ft_strndup(MINUS_SOLO, 1));
	}
	else if (**str != '-' && (data->converter_id == CI_DMIN || data->converter_id == CI_I))
	{
		return ((data->plus_flag) ? ft_strndup(PLUS_SOLO, 1) :
			((data->space_flag) ? ft_strndup(SPACE_SOLO, 1) : ft_strnew(1)));
	}
	else if (data->hashtag_flag)
	{
		if (data->converter_id == CI_XMIN && data->precision != 0 && ft_strcmp(*str, ZERO_SOLO) != 0)
			return (ft_strndup(PREFIX_XMIN, 2));
		else if (data->converter_id == CI_XMAJ && data->precision != 0 && ft_strcmp(*str, ZERO_SOLO) != 0)
			return (ft_strndup(PREFIX_XMAJ, 2));
		else if (data->converter_id == CI_OMIN && ft_strcmp(*str, ZERO_SOLO) != 0)
			return (ft_strndup(ZERO_SOLO, 1));
		else if (data->converter_id == CI_P)
			return (ft_strndup(PREFIX_XMIN, 2));
	}
	return (ft_strnew(1));
}
