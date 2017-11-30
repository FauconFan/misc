/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:49:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 11:45:20 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "treat_data_utils.h"

/*
**	init the struct and fill it
*/

char			*init_and_set_values_treat_data(char *str, t_treat_data **data)
{
	if ((*data = (t_treat_data *)malloc(sizeof(t_treat_data))) == 0)
		return (0);
	(*data)->hashtag_flag = 0;
	(*data)->zero_flag = 0;
	(*data)->minus_flag = 0;
	(*data)->plus_flag = 0;
	(*data)->space_flag = 0;
	(*data)->gabarit = -1;
	(*data)->precision = -1;
	(*data)->length_modifier_id = -1;
	(*data)->converter_id = -1;
	str = set_flags_treat_data(str, *data);
	str = set_gabarit_treat_data(str, *data);
	str = set_precision_treat_data(str, *data);
	str = set_length_modifer(str, *data);
	str = set_converter_treat_data(str, *data);
	if (str == 0)
		free(*data);
	return (str);
}

/*
** treat_data
*/

void			treat_data(t_treat_data *data, va_list va, t_string_buffer *sb)
{
	if (data->converter_id == -1 || data->converter_id >= 24)
		return ;
	if (data->converter_id == CI_CMIN)
		process_normal_char(va, data, sb);
	else if (data->converter_id == CI_SMIN)
		process_normal_string(va, data, sb);
	else if (data->converter_id == CI_CMAJ)
		process_special_char(va, data, sb);
	else if (data->converter_id == CI_SMAJ)
		process_special_string(va, data, sb);
	else if (data->converter_id == CI_SEP)
		process_sep(data, sb);
	else if (data->converter_id >= 12 && data->converter_id <= 21)
		process_numbers(va, data, sb);
	else
	{
		ft_putstr_fd("should never happen", 2);
	}
}

/*
**	treat the data when a '%' is found
*/

char			*treat_sep(char *str, va_list va, t_string_buffer *sb)
{
	t_treat_data	*data;

	if ((str = init_and_set_values_treat_data(++str, &data)) == 0)
		return (str);
	treat_data(data, va, sb);
	free(data);
	return (str);
}

/*
**	parse the data properly. It use string buffer
*/

int				process(char *str, va_list va, t_string_buffer *sb,
							char **to_print, int *len_to_print)
{
	char				*tmp;
	int					pos_first_percent;

	while ((pos_first_percent = ft_strcpos(str, SEPERATOR)) != -1)
	{
		if ((tmp = ft_strsub(str, 0, pos_first_percent)) == 0)
			return (-1);
		sb_append_normal(sb, tmp);
		str += pos_first_percent;
		free(tmp);
		if ((str = treat_sep(str, va, sb)) == 0)
			return (-1);
	}
	sb_append_normal(sb, str);
	return (build_str(sb, to_print, len_to_print));
}
