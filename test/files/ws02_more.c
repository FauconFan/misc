/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws02_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:55:22 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"

int	main(void)
{
	int		i;
	char	*addr;

	start_test();
	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	show_alloc_mem();
	end_test();
	return (0);
}
