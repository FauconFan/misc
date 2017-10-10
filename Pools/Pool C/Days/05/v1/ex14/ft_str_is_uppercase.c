/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:30:54 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:21:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		up(char c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

int		ft_str_is_uppercase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (up(str[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
