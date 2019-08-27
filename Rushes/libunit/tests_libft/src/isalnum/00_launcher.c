/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:00:24 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:51:18 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void	isalnum_launcher(void)
{
	t_unit_test		*loader_isalnum;

	init_tests(&loader_isalnum, "isalnum");
	load_test(loader_isalnum, "basic_test_1", &basic_test_isalnum01);
	load_test(loader_isalnum, "basic_test_2", &basic_test_isalnum02);
	load_test(loader_isalnum, "empty_test", &basic_test_isalnum03);
	finish_tests(loader_isalnum);
}
