/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/19 15:53:42 by jpriou           ###   ########.fr       */
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
	else
	{
		if (data->converter_id == CI_DMIN)
			return ((long long)va_arg(va, int));
		else
			return ((long long)va_arg(va, long int));
	}
	die(SNA);
	return (0);
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
	else
	{
		return ((unsigned long long)va_arg(va, unsigned int));
	}
	die(SNA);
	return (0);
}

static char					*get_first_rep_ci_numbers(
								va_list va, t_treat_data *res)
{
	if (res->converter_id == CI_DMIN || res->converter_id == CI_I)
		return (ft_lltoa_base(get_rep_no_unsigned(va, res), "0123456789"));
	else if (res->converter_id == CI_OMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "01234567"));
	else if (res->converter_id == CI_UMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789"));
	else if (res->converter_id == CI_XMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789abcdef"));
	else if (res->converter_id == CI_XMAJ)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789ABCDEF"));
	die(SNA);
	return (0);
}

char						*get_rep_with_prec(va_list va, t_treat_data *data)
{
	char	*str;
	char	*tmp;

	str = get_first_rep_ci_numbers(va, data);
	if (data->precision > (int)ft_strlen(str))
	{
		tmp = ft_strsetnew(data->precision, '0');
		ft_strncpy(tmp + data->precision - ft_strlen(str), str, ft_strlen(str));
		free(str);
		str = tmp;
	}
	else if (data->precision == 0 && ft_strcmp("0", str) == 0)
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
		return ("-");
	}
	else if (**str != '-' && (data->converter_id == CI_DMIN || data->converter_id == CI_I))
	{
		return ((data->plus_flag) ? "+" : ((data->space_flag) ? " " : ""));
	}
	else if (data->hashtag_flag)
	{
		if (data->converter_id == CI_XMIN)
			return ("0x");
		else if (data->converter_id == CI_XMAJ)
			return ("0X");
		else if (data->converter_id == CI_OMIN)
			return ("0");
	}
	return ("");
}
