/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws11_malloc_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:50:53 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 14:11:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ft_malloc.h"
#include <string.h>

static void		test(size_t l)
{
	void	*v;

	v = malloc(l);
	ft_put_str("Testing : ");
	ft_put_uint_ln(l);
	ft_put_str("malloc size = ");
	ft_put_uint_ln(malloc_size(v));
	ft_put_str("malloc asked size = ");
	ft_put_uint_ln(malloc_asked_size(v));
	ft_put_str("malloc good size = ");
	ft_put_uint_ln(malloc_good_size(l));
}

static void		test_malloc_zone(t_malloc_zone *mz, size_t l)
{
	void	*v;

	v = ft_malloc_zone_malloc(mz, l);
	ft_put_str("Testing : ");
	ft_put_uint_ln(l);
	ft_put_str("malloc size = ");
	ft_put_uint_ln(ft_malloc_zone_malloc_size(mz, v));
	ft_put_str("malloc asked size = ");
	ft_put_uint_ln(ft_malloc_zone_malloc_asked_size(mz, v));
}

int				main(void)
{
	t_malloc_zone	*mz;

	start_test();
	mz = ft_malloc_zone_create();
	test(12);
	test(24);
	test(40);
	test(1000);
	test(2000);
	test(SMALL_MAX + 1);
	test(1000 * 1000 * 1000);
	test_malloc_zone(mz, 12);
	test_malloc_zone(mz, 24);
	test_malloc_zone(mz, 40);
	test_malloc_zone(mz, 1000);
	test_malloc_zone(mz, 2000);
	test_malloc_zone(mz, SMALL_MAX + 1);
	test_malloc_zone(mz, 1000 * 1000 * 1000);
	ft_malloc_zone_destroy(mz);
	end_test();
	return (0);
}
