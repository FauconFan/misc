/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:55:56 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		isascii_launcher(void)
{
	t_unit_test		*loader_isascii;

	init_tests(&loader_isascii, "isascii");
	load_test(loader_isascii, "basic_test_1", &basic_test_isascii01);
	finish_tests(loader_isascii);
}
