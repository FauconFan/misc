/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:47:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:09:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		atoi_launcher(void)
{
	t_unit_test		*loader_atoi;

	init_tests(&loader_atoi, "atoi");
	load_test(loader_atoi, "basic_test_1", &basic_test_atoi01);
	load_test(loader_atoi, "basic_test_2", &basic_test_atoi02);
	load_test(loader_atoi, "basic_test_3", &basic_test_atoi03);
	finish_tests(loader_atoi);
}
