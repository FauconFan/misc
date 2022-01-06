/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns05_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:52:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:53:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

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
		free(addr);
		i++;
	}
	end_test();
	return (0);
}
