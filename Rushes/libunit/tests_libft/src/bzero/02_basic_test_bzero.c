/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_test_bzero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:06:05 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:49:50 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_bzero02(void)
{
	char *s1;
	char *s2;

	s1 = "azerty";
	s2 = "azerty";
	my_bzero(s1, 4);
	ft_bzero(s2, 4);
	if (ft_strcmp(s1, s2) == 0)
		return (0);
	else
		return (-1);
}
