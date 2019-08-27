/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:52:25 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:22:23 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	*my_memdup(const void *s, size_t n)
{
	void *dup;

	if (!s)
		return (NULL);
	if ((dup = (void*)malloc(sizeof(unsigned char) * n)) == NULL)
		my_protect_malloc();
	return (my_memcpy(dup, s, n));
}
