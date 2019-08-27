/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:27:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:57:55 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		itoa_launcher(void)
{
	t_unit_test		*loader_itoa;

	init_tests(&loader_itoa, "itoa");
	load_test(loader_itoa, "basic_test_1", &basic_test_itoa01);
	load_test(loader_itoa, "basic_test_2", &basic_test_itoa02);
	load_test(loader_itoa, "basic_test_3", &basic_test_itoa03);
	load_test(loader_itoa, "basic_test_4", &basic_test_itoa04);
	load_test(loader_itoa, "basic_test_5", &basic_test_itoa05);
	finish_tests(loader_itoa);
}
