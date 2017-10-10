/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 13:47:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 08:50:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		index;

	index = 0;
	while (s1[index] == s2[index] && index < n - 1)
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (s1[index] - s2[index]);
}
