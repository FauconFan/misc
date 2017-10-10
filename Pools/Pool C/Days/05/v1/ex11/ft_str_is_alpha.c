/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:35:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:20:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		low_case(char c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

int		up_case(char c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

int		ft_str_is_alpha(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (up_case(str[index]) == 0 && low_case(str[index]) == 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
