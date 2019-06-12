/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns10_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:54:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 10:09:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void		print(char *str)
{
	write(1, str, strlen(str));
}

int			main(void)
{
	start_test();
	char *addr = calloc((size_t)(1) << 42, (size_t)(1) << 42);
	if (addr == NULL)
		print("This is ok\n");
	else
		print("This is terribly bad\n");
	end_test();
}
