/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_isdigit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:20:18 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:23:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_isdigit01(void)
{
	char	c;
	int		a;
	int		b;

	c = 'B';
	a = my_isdigit(c);
	b = ft_isdigit(c);
	if (a == b)
		return (0);
	return (-1);
}
