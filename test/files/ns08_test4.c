/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns08_test4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:54:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:55:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void		print(char *s)
{
	write(1, s, strlen(s));
}

int			main(void)
{
	char *addr;

	start_test();
	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
	end_test();
}
