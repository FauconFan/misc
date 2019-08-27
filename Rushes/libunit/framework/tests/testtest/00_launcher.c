/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:28:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:51:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testtest.h"

void		testtest_valid(void)
{
	t_unit_test		*loader_testtest;

	init_tests(&loader_testtest, "testall");
	load_test(loader_testtest, "01 should be ok", &ft_ok01);
	load_test(loader_testtest, "02 should be ko", &ft_ko02);
	load_test(loader_testtest, "03 should segfault", &ft_segf03);
	load_test(loader_testtest, "04 should bus error", &ft_buse04);
	finish_tests(loader_testtest);
}
