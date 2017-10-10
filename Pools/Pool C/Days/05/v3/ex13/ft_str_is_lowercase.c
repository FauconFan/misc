/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:30:54 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:20:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lower(char c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

int		ft_str_is_lowercase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (lower(str[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
