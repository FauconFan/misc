/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_memcpy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:27:44 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 16:11:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

int		basic_test_memcpy01(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Salut!";
	s2 = "000000";
	s3 = "000000";
	my_memcpy(s2, s1, 0);
	ft_memcpy(s3, s1, 0);
	if (ft_strcmp(s3, s2) == 0)
		return (0);
	else
		return (-1);
}
