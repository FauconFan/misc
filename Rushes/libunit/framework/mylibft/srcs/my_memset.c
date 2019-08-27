/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:44:28 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 14:58:41 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	*my_memset(void *b, int c, size_t len)
{
	c = (unsigned char)c;
	while (len)
		((unsigned char*)b)[--len] = c;
	return (b);
}
