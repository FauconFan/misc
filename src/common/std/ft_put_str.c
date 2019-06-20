/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 13:32:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_put_str(const char *str)
{
	size_t	len;

	if (str == NULL)
		str = "(NULL)";
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	ft_put_str_ln(const char *str)
{
	ft_put_str(str);
	write(1, "\n", 1);
}
