/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 13:24:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers_utils.h"

int		check_octal(char **res, t_treat_data *data)
{
	if (data->converter_id == CI_XMIN || data->converter_id == CI_XMAJ)
	{
		if (data->precision == 0 && ft_strcmp(*res, "0"))
		{
			free(*res);
			*res = ft_strdup("");
		}
		else
		{
			
		}
		return (1);
	}
	else if (data->converter_id == CI_OMIN)
	{
		return (1);
	}
	return (0);
}