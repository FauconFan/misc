/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_isascii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:05:56 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:17:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_isascii01(void)
{
	int		c;
	int		a;
	int		b;

	c = -42;
	while (c++ < 200)
	{
		a = my_isascii(c);
		b = ft_isascii(c);
		if (a != b)
			return (-1);
	}
	return (0);
}
