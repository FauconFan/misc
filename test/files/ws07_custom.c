/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws07_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:54:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 10:12:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft_malloc.h>

int			main(void)
{
	char *addr[4];

	start_test();
	addr[0] = malloc(16);
	addr[1] = malloc(1024);
	addr[2] = malloc(1024 * 1024);
	addr[3] = malloc(1024 * 1024 * 16);
	free(addr[2]);
	show_alloc_mem();
	end_test();
}
