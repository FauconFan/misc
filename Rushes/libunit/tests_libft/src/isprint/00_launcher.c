/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:23:58 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:57:18 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		isprint_launcher(void)
{
	t_unit_test		*loader_isprint;

	init_tests(&loader_isprint, "isprint");
	load_test(loader_isprint, "basic_test_1", &basic_test_isprint01);
	finish_tests(loader_isprint);
}
