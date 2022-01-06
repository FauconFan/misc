/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws05_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:56:40 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 08:27:06 by jpriou           ###   ########.fr       */
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
	while (i < 2)
	{
		write(1, "=====================\n", 22);
		show_alloc_mem();
		write(1, "=========\n", 10);
		addr = (char*)malloc(1024);
		addr[0] = 42;
		show_alloc_mem();
		write(1, "=========\n", 10);
		free(addr);
		show_alloc_mem();
		i++;
	}
	end_test();
	return (0);
}
