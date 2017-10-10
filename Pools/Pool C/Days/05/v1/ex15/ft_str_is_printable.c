/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:02:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:22:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_printable(char c)
{
	return ((c < 32 || c == 127) ? 1 : 0);
}

int		ft_str_is_printable(char *str)
{
	int		index;

	while (str[index] != '\0')
	{
		if (is_printable(str[index]) == 1)
			return (0);
		index++;
	}
	return (1);
}
