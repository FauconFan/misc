/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:05:58 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 17:07:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_strncpos(const char *str, size_t n, char c)
{
	int		i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (n != 0 && str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
		--n;
	}
	return (-1);
}
