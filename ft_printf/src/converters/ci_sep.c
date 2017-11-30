/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:56:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 19:56:25 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_sep.h"

void	process_sep(t_treat_data *data, t_string_buffer *sb)
{
	char	*res;
	char	*tmp;

	res = "%";
	if (data->gabarit > 1)
	{
		tmp = ft_strsetnew(data->gabarit, (data->zero_flag) ? '0' : ' ');
		if (data->minus_flag)
			ft_strncpy(tmp, res, 1);
		else
			ft_strncpy(tmp + data->gabarit - 1, res, 1);
		sb_append_special(sb, tmp, data->gabarit, data->gabarit);
		free(tmp);
	}
	else
	{
		sb_append_special(sb, res, 1, 1);
	}
}
