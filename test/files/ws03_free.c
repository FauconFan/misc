/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws03_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:55:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:55:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft_malloc.h>

int	main(void)
{
	char	*addr;

	start_test();
	addr = (char *)malloc(1024);
	show_alloc_mem();
	free(addr);
	show_alloc_mem();
	end_test();
}
