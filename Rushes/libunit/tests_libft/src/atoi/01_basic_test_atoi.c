/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_atoi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:49:45 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 16:12:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_atoi01(void)
{
	int		a;
	int		b;
	char	*s;

	s = "\t \n \v \f \r +9128db b";
	a = my_atoi(s);
	b = ft_atoi(s);
	if (a == b)
		return (0);
	return (-1);
}
