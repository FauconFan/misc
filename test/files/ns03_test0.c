/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns03_test0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:52:11 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:52:28 by jpriou           ###   ########.fr       */
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
		i++;
	}
	end_test();
	return (0);
}
