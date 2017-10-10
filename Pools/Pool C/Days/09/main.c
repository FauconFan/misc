/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 16:51:23 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 13:18:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ex00/ft_generic.c"
#include "ex01/ft_takes_place.c"
#include "ex07/ft_collatz_conjecture.c"
#include "ex13/ft_compact.c"

int		main(void)
{
	ft_generic();
	int index = 0;
	while (index <= 24)
	{
		ft_takes_place(index++);
	}
	index = 0;
	while (index < 30)
	{
		printf("%d : %d\n", index, ft_collatz_conjecture(index));
		index++;
	}
}
