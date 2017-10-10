/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 11:20:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 08:50:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_good_place(char *str, char *to_find, int index)
{
	int		loop;

	loop = 0;
	while (str[index + loop] == to_find[loop] && to_find[loop] != '\0')
	{
		loop++;
	}
	if (to_find[loop] == '\0')
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == to_find[0] && is_good_place(str, to_find, index) == 1)
			return (str + index);
		index++;
	}
	return (0);
}
