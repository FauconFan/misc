/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnotcpos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:12:03 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 23:21:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_strnotcpos(const char *str, char c)
{
	int		i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (i);
		++i;
	}
	return (-1);
}
