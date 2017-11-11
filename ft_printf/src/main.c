/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 17:14:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "string_buffer.h"
#include "ft_printf.h"

int 	main(void)
{
	char	c;
	int		p;

	ft_printf("%sCoucou %sje mapelle %s", "42", "oui", "sil te plait\n");
	c = '5';
	p = 1;
	for (int i = 0; i < 1024 * 1024; ++i)
	{
		printf("%S\n", &p);
	}
	printf("%s\n", ft_convert_base("42", "0123456789", "0123456789ABCDEF"));
	return (0);
}