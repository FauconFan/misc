/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syms_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:44:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 17:53:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_syms_free(t_sym *symbols, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (symbols[i].name != NULL)
			free(symbols[i].name);
		++i;
	}
	free(symbols);
}
