/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 21:13:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:27:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer_utils.h"

unsigned int		length_tot(t_string_buffer *res)
{
	unsigned int	size;
	int				index;

	size = 0;
	index = 0;
	while (index < res->size_actu)
	{
		size += ft_strlen(res->tab[index]);
		index++;
	}
	return (size);
}
