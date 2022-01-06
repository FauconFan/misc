/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws10_malloc_zone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:01:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:04:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"
#include <string.h>

int		main(void)
{
	char			*addr[2];
	t_malloc_zone	*mzone;

	start_test();
	mzone = ft_malloc_zone_create();
	addr[0] = malloc(16);
	addr[0][0] = 0;
	strcat(addr[0], "Coucou\n");
	addr[1] = ft_malloc_zone_malloc(mzone, 32);
	addr[1][1] = 0;
	strcat(addr[1], "In the malloc zone");
	show_alloc_mem_hex();
	ft_malloc_zone_show_alloc_mem_hex(mzone);
	ft_malloc_zone_destroy(mzone);
	end_test();
	return (0);
}
