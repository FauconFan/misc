/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:53:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/06 14:55:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		numeric(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int		ft_str_is_numeric(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (numeric(str[index]) == 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
