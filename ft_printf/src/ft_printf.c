/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/13 08:33:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
int 	ft_printf(char *str, ...)
{
	ft_putstr(str);
	va_list va;

	va_start(va, str);
	ft_putstr(va_arg(va, char *));
	va_end(va);
	return (0);
}