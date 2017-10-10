/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:31:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 09:37:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int		index[2];

	index[0] = 0;
	while (factory[index[0]])
	{
		index[1] = 0;
		while (factory[index[0]][index[1]])
		{
			free(factory[index[0]][index[1]]);
			index[1]++;
		}
		free(factory[index[0]]);
		index[0]++;
	}
	free(factory);
}
