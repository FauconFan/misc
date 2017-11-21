/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:27:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:54:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_character.h"

void	print_special_char(va_list va, t_treat_data *data, int *return_func)
{
	char	c;
	int		index;

	c = (char)va_arg(va, int);
	if (data->minus_flag)
		ft_putchar(c);
	index = 0;
	while (index < data->gabarit - 1)
	{
		ft_putchar((data->zero_flag) ? '0' : ' ');
		*return_func = *return_func + 1;
		index++;
	}
	if (data->minus_flag == 0)
		ft_putchar(c);
	*return_func = *return_func + 1;
}
