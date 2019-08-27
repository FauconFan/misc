/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:52:13 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 12:55:27 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

size_t	my_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_dst;
	size_t len_src;

	len_dst = my_strlen(dst);
	len_src = my_strlen(src);
	if (size < len_dst)
		return (size + len_src);
	i = 0;
	while (src[i] && (len_dst + i + 1) < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
