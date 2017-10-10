/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:21:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 09:28:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_button(int i, int j, int k)
{
	if (i == j && j == k)
		return (i);
	if (i == j)
		return (i);
	if (j == k)
		return (j);
	if (i == k)
		return (i);
	if (i < j)
	{
		if (k < i)
			return (i);
		else if (k > j)
			return (j);
		return (k);
	}
	if (k > i)
		return (i);
	else if (k < j)
		return (j);
	return (k);
}
