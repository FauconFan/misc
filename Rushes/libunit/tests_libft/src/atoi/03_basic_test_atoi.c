/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_test_atoi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:49:45 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:48:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_atoi03(void)
{
	int		a;
	int		b;
	char	*s;

	s = "S12";
	a = my_atoi(s);
	b = ft_atoi(s);
	if (a == b)
		return (0);
	else
		return (-1);
}
