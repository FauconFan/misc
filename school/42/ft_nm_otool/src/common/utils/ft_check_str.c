/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 07:43:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 18:41:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_check_str(char *s, size_t remain, size_t *size)
{
	*size = 0;
	while (remain != 0 && *s != 0 && ft_isprint(*s))
	{
		s++;
		--remain;
		++*size;
	}
}
