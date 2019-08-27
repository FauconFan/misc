/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:19:03 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:56:33 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		isdigit_launcher(void)
{
	t_unit_test		*loader_isdigit;

	init_tests(&loader_isdigit, "isdigit");
	load_test(loader_isdigit, "basic_test_1", &basic_test_isdigit01);
	load_test(loader_isdigit, "basic_test_2", &basic_test_isdigit02);
	finish_tests(loader_isdigit);
}
