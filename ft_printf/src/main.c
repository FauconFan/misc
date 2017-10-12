/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/12 21:59:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "string_buffer.h"

int 	main(void)
{
	t_string_buffer *test;
	char 			*str;

	test = new_string_buffer();
	sb_append(test, "Coucou");
	sb_append(test, " Je m'appelle Jean-Michel !");
	str = sb_to_string_and_free_all(test);
	ft_putstr(str);
	free(str);
	return (0);
}