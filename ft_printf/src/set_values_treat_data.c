/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:05:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:36:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_values_treat_data.h"

char	*set_flags_treat_data(char *str, t_treat_data *data)
{
	if (str == 0 || *str == 0)
		return (str);
	if (*str == HASHTAG_FLAG)
		data->hashtag_flag = 1;
	else if (*str == ZERO_FLAG)
		data->zero_flag = 1;
	else if (*str == MINUS_FLAG)
		data->minus_flag = 1;
	else if (*str == PLUS_FLAG)
		data->plus_flag = 1;
	else if (*str == SPACE_FLAG)
		data->space_flag = 1;
	else
		return (str);
	return (set_flags_treat_data(str + 1, data));
}

char	*set_gabarit_treat_data(char *str, t_treat_data *data)
{
	if (str == 0 || *str == 0)
		return (str);
	if (ft_isdigit(*str))
	{
		data->gabarit = 0;
		while (ft_isdigit(*str))
		{
			data->gabarit = data->gabarit * 10 + *str - '0';
			str++;
			if (*str == 0)
				return (str);
		}
	}
	return (str);
}

char	*set_precision_treat_data(char *str, t_treat_data *data)
{
	if (str == 0 || *str == 0)
		return (str);
	if (*str == SEP_PRECISION)
	{
		str++;
		if (*str == 0)
			return (0);
		data->precision = 0;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
			{
				data->precision = data->precision * 10 + *str - '0';
				str++;
				if (*str == 0)
					return (str);
			}
		}
	}
	return (str);
}

char	*set_length_modifer(char *str, t_treat_data *data)
{
	if (str == 0 || *str == 0)
		return (str);
	if (*str == 'j')
		data->length_modifier_id = LM_J;
	else if (*str == 'z')
		data->length_modifier_id = LM_Z;
	else if (*str == 'h')
	{
		data->length_modifier_id = LM_H;
		if (*(str + 1) == 'h' && str++)
			data->length_modifier_id = LM_HH;
	}
	else if (*str == 'l')
	{
		data->length_modifier_id = LM_L;
		if (*(str + 1) == 'l' && str++)
			data->length_modifier_id = LM_LL;
	}
	else
		str--;
	str++;
	return (str);
}

char	*set_converter_treat_data(char *str, t_treat_data *data)
{
	if (str == 0 || *str == 0)
		return (str);
	data->converter_id = set_converter_treat_data2(ft_toupper(*str));
	if (data->converter_id != -1 && ft_islower(*str))
		data->converter_id = data->converter_id - 1;
	if (*str == 'p')
		data->converter_id = CI_P;
	else if (*str == 'i')
		data->converter_id = CI_I;
	else if (*str == 'n')
		data->converter_id = CI_N;
	else if (*str == SEPERATOR)
		data->converter_id = CI_SEP;
	if (data->converter_id == -1)
		return (str);
	update_uppercase_for_l_lm(*str, data);
	return (++str);
}
