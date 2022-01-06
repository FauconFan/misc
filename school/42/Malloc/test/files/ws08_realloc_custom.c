/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws08_realloc_custom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:56:00 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 08:28:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"
#include <string.h>

void	print(char *str)
{
	write(1, str, strlen(str));
	write(1, "\n", 1);
}

int		main(void)
{
	char	*addr1;
	char	*addr3;

	start_test();
	addr1 = malloc(16);
	addr1[0] = 0;
	strcpy(addr1, "Test");
	print(addr1);
	addr3 = realloc(addr1, 32);
	strcat(addr3, " et de deux");
	print(addr3);
	show_alloc_mem();
	end_test();
	return (0);
}
