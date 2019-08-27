/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:24:18 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:23:35 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strnew(size_t size)
{
	char *string;

	if ((string = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		my_protect_malloc();
	my_bzero(string, size + 1);
	return (string);
}
