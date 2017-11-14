/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/14 23:18:15 by jpriou           ###   ########.fr       */
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

static char					*check_hastag_flag_octal(
									char *tmp, t_treat_data *data)
{
	char	*prefix;
	char	*str;

	if (data->converter_id == CI_XMIN)
		prefix = "0x";
	else if (data->converter_id == CI_XMAJ)
		prefix = "0X";
	else
		die(SNA);
	if (data->hashtag_flag == 0 || ft_strcmp(tmp, "0") == 0)
		return (tmp);
	str = ft_strjoin(prefix, tmp);
	free(tmp);
	return (str);
}

char						*get_first_rep_ci_numbers(
								va_list va, t_treat_data *res)
{
	char	*tmp;

	if (res->converter_id == CI_DMIN || res->converter_id == CI_I)
		return (ft_lltoa_base(get_rep_no_unsigned(va, res), "0123456789"));
	else if (res->converter_id == CI_OMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "01234567"));
	else if (res->converter_id == CI_UMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789"));
	else if (res->converter_id == CI_XMIN)
	{
		tmp = ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789abcdef");
		return (check_hastag_flag_octal(tmp, res));
	}
	else if (res->converter_id == CI_XMAJ)
	{
		tmp = ft_ulltoa_base(get_rep_unsigned(va, res), "0123456789ABCDEF");
		return (check_hastag_flag_octal(tmp, res));
	}
	die(SNA);
	return (0);
}

char						*adapt_params_function_ci_numbers(
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
