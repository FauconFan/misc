/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_test_isalpha.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:05:56 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:13:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_isalpha02(void)
{
	char	c;
	int		a;
	int		b;

	c = '4';
	a = my_isalpha(c);
	b = ft_isalpha(c);
	if (a == b)
		return (0);
	else
		return (-1);
}
