/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws06_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:57:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 08:27:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"

int	main(void)
{
	void	*v;

	start_test();
	v = malloc(1);
	v = malloc(2);
	v = malloc(3);
	v = malloc(4);
	v = malloc(5);
	v = malloc(6);
	v = malloc(7);
	v = malloc(8);
	v = malloc(9);
	v = malloc(10);
	show_alloc_mem();
	end_test();
	return (0);
}
