/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws06_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:57:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"

int	main(void)
{
	start_test();
	malloc(1);
	malloc(2);
	malloc(3);
	malloc(4);
	malloc(5);
	malloc(6);
	malloc(7);
	malloc(8);
	malloc(9);
	malloc(10);
	show_alloc_mem();
	end_test();
	return (0);
}
