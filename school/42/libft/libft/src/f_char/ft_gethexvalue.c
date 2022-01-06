/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethexvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:04:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 16:16:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_gethexvalue(char c)
{
	c = c % 16;
	if (c < 10)
		return ('0' + c);
	return ('A' + c - 10);
}
