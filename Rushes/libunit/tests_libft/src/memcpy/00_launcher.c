/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:50:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:10:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		memcpy_launcher(void)
{
	t_unit_test		*loader_memcpy;

	init_tests(&loader_memcpy, "memcpy");
	load_test(loader_memcpy, "basic_test_1", &basic_test_memcpy01);
	load_test(loader_memcpy, "basic_test_2", &basic_test_memcpy02);
	finish_tests(loader_memcpy);
}
