/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 08:36:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:58:30 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		strlen_launcher(void)
{
	t_unit_test		*loader_strlen;

	init_tests(&loader_strlen, "strlen");
	load_test(loader_strlen, "basic_test_1", &strlen_simple_test_01);
	load_test(loader_strlen, "basic_test_2", &strlen_simple_test_02);
	load_test(loader_strlen, "empty_test", &strlen_empty_test);
	finish_tests(loader_strlen);
}
