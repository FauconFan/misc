/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:08 by dwald             #+#    #+#             */
/*   Updated: 2016/12/13 20:26:22 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	void	*cpy;

	cpy = dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (cpy);
}
