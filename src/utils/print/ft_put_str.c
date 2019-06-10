/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:43:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_put_str(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	ft_put_str_ln(char *str)
{
	ft_put_str(str);
	write(1, "\n", 1);
}
