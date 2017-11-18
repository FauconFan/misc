/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/18 19:10:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers.h"

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

/*
** 1 => left empty
** 2 => right empty
** 3 => both zero
*/

static char			*adaptholala(char *prefix, char *str, int gabarit, int id)
{
	char	*tmp;

	tmp = ft_strsetnew(gabarit, (id == 3) ? '0' : ' ');
	if (id == 2)
		ft_strncpy(tmp + gabarit - ft_strlen(prefix) - ft_strlen(str), prefix,
			ft_strlen(prefix));
	else
		ft_strncpy(tmp, prefix, ft_strlen(prefix));
	if (id == 1)
		ft_strncpy(tmp + ft_strlen(prefix), str, ft_strlen(str));
	else
		ft_strncpy(tmp + gabarit - ft_strlen(str), str, ft_strlen(str));
	return (tmp);
}

static char			*test(char *prefix, char *str, t_treat_data *data)
{
	char	*res;

	if (data->gabarit > (int)(ft_strlen(str) + ft_strlen(prefix)))
	{
		if (data->minus_flag)
			res = adaptholala(prefix, str, data->gabarit, 1);
		else if (data->precision != -1)
			res = adaptholala(prefix, str, data->gabarit, 2);
		else
		{
			if (data->zero_flag)
			{
				res = adaptholala(prefix, str, data->gabarit, 3);
			}
			else
				res = adaptholala(prefix, str, data->gabarit, 2);
		}
	}
	else
		res = adaptholala(prefix, str, ft_strlen(str) + ft_strlen(prefix), 1);
	free(str);
	return (res);
}

char						*adapt2(va_list va, t_treat_data *data)
{
	char	*str;
	char	*prefix;
	char	*tmp;

	str = get_first_rep_ci_numbers(va, data);
	if (data->precision > (int)ft_strlen(str))
	{
		tmp = ft_strsetnew(data->precision, '0');
		ft_strncpy(tmp + data->precision - ft_strlen(str), str, ft_strlen(str));
		free(str);
		str = tmp;
	}
	prefix = "";
	if (*str == '-')
	{
		tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
		prefix = "-";
		free(str);
		str = tmp;
	}
	else if (*str != '-' && (data->converter_id == CI_DMIN || data->converter_id == CI_I))
	{
		if (data->plus_flag)
		{
			prefix = "+";
		}
		else if (data->space_flag)
		{
			prefix = " ";
		}
	}
	else if (data->hashtag_flag)
	{
		if (data->converter_id == CI_XMIN)
			prefix = "0x";
		else if (data->converter_id == CI_XMAJ)
			prefix = "0X";
		else if (data->converter_id == CI_OMIN)
			prefix = "0";
	}
	return (test(prefix, str, data));
}