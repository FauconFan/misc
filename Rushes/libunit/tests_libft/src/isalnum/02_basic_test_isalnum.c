/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_test_isalnum.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:28:14 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:04:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_isalnum02(void)
{
	char	c;
	int		a;
	int		b;

	c = '2';
	a = my_isalnum(c);
	b = ft_isalnum(c);
	if (a == b)
		return (0);
	else
		return (-1);
}
