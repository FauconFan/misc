/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_protect_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:14:00 by dwald             #+#    #+#             */
/*   Updated: 2017/10/20 17:08:37 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	my_protect_malloc(void)
{
	my_putstr_fd("Error: memory allocation failed\n", 2);
	exit(0);
}
