/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:38:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 16:54:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

size_t	ft_antou(const char *str, size_t n)
{
	size_t	l;
	int		cpos;

	l = 0;
	while (n != 0 && (cpos = ft_strcpos(BASE_DEC, *str)) >= 0)
	{
		l = l * 10 + (size_t)cpos;
		--n;
		++str;
	}
	return (l);
}
