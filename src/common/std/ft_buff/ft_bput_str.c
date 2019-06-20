/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bput_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:03:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_bput_str(const char *str)
{
	if (str == NULL)
		str = "(NULL)";
	ft_buff_put(str);
}

void	ft_bput_str_ln(const char *str)
{
	ft_buff_put(str);
	ft_buff_put("\n");
}
