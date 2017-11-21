/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:49:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:38:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "treat_data_utils.h"

static int			is_numeri(int id)
{
	return (id >= 12 && id <= 21);
}

t_treat_data	*init_treat_data(void)
{
	t_treat_data	*data;

	if ((data = (t_treat_data *)malloc(sizeof(t_treat_data))) == 0)
		return (0);
	data->hashtag_flag = 0;
	data->zero_flag = 0;
	data->minus_flag = 0;
	data->plus_flag = 0;
	data->space_flag = 0;
	data->gabarit = -1;
	data->precision = -1;
	data->length_modifier_id = -1;
	data->converter_id = -1;
	return (data);
}

char			*set_values_treat_data(char *str, t_treat_data *data)
{
	str = set_flags_treat_data(str, data);
	str = set_gabarit_treat_data(str, data);
	str = set_precision_treat_data(str, data);
	str = set_length_modifer(str, data);
	str = set_converter_treat_data(str, data);
	return (str);
}

char			*treat_data(t_treat_data *data, va_list va, int *return_func)
{
	char	*res;

	if (data->converter_id == -1)
		return (0);
	if (data->converter_id == CI_CMIN)
	{
		special_char(va, data, return_func);
		return (0);
	}
	else if (is_numeri(data->converter_id))
	{
		return (numeri(va, data));
	}
	res = get_first_rep(va, data);
	res = adapt_flags_gabarit_precision(res, va, data);
	return (res);
}

void			free_treat_data(t_treat_data *data)
{
	free(data);
}

void			print_values(t_treat_data *data)
{
	ft_putstr("# : ");
	ft_putnbrl(data->hashtag_flag);
	ft_putstr("0 : ");
	ft_putnbrl(data->zero_flag);
	ft_putstr("- : ");
	ft_putnbrl(data->minus_flag);
	ft_putstr("+ : ");
	ft_putnbrl(data->plus_flag);
	ft_putstr("  : ");
	ft_putnbrl(data->space_flag);
	ft_putstr("gabarit : ");
	ft_putnbrl(data->gabarit);
	ft_putstr("precision : ");
	ft_putnbrl(data->precision);
	ft_putstr("length_modifier : ");
	ft_putnbrl(data->length_modifier_id);
	ft_putstr("converter : ");
	ft_putnbrl(data->converter_id);
}
