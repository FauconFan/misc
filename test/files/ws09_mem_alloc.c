/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws09_mem_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:56:00 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"
#include <string.h>

int		main(void)
{
	char	*addr[4];
	size_t	i;

	start_test();
	addr[0] = malloc(40);
	addr[0][0] = 0;
	strcat(addr[0], "Coucou, je fais un premier test");
	addr[1] = malloc(4);
	ft_bzero(addr[1], 4);
	addr[2] = malloc(1024);
	i = 0;
	while (i < 1024)
	{
		addr[2][i] = i % 256;
		++i;
	}
	addr[3] = malloc(0);
	show_alloc_mem();
	show_alloc_mem_hex();
	end_test();
	return (0);
}
