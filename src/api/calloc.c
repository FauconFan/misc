/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:18:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
	char	*v;
	size_t	i;

	v = malloc(nmemb * size);
	i = 0;
	while (i < nmemb * size)
	{
		v[i] = 0;
		++i;
	}
	return (v);
}
