/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 09:08:24 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 09:12:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		operation_treatment(char c, int a, int b)
{
	if (c == '+')
		return (add(a, b));
	else if (c == '-')
		return (substract(a, b));
	else if (c == '*')
		return (times(a, b));
	else if (c == '/')
		return (divide(a, b));
	else if (c == '%')
		return (modulo(a, b));
	return (0);
}
