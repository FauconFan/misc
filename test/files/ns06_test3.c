/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns06_test3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:53:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:53:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define M (1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char *addr1;
	char *addr3;

	start_test();
	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	end_test();
	return (0);
}
