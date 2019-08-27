/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_isprint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:23:55 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:44:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_isprint01(void)
{
	int		c;
	int		a;
	int		b;

	c = -42;
	while (c++ < 200)
	{
		a = my_isprint(c);
		b = ft_isprint(c);
		if (a != b)
			return (-1);
	}
	return (0);
}
