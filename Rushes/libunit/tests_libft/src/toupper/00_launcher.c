/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:52:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:59:02 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		toupper_launcher(void)
{
	t_unit_test		*loader_toupper;

	init_tests(&loader_toupper, "toupper");
	load_test(loader_toupper, "basic_test_1", &toupper_basic_test1);
	load_test(loader_toupper, "basic_test_2", &toupper_basic_test2);
	load_test(loader_toupper, "basic_test_3", &toupper_basic_test3);
	finish_tests(loader_toupper);
}
