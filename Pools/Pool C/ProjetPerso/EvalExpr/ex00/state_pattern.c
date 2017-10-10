/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:31:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 13:38:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "ft_list.h"

void	set_pattern(int mode, int *tab)
{
	if (mode == 1)
	{
		tab[0] = 1;
		tab[1] = 0;
		tab[2] = 1;
		tab[3] = -1;
	}
	else if (mode == 2)
	{
		tab[0] = 0;
		tab[1] = 1;
		tab[2] = 0;
		tab[3] = 1;
		tab[4] = 0;
		tab[5] = -1;
	}
	else
		set_pattern2(mode, tab);
}

void	set_pattern2(int mode, int *tab)
{
	if (mode == 3)
	{
		tab[0] = 1;
		tab[1] = 0;
		tab[2] = 1;
		tab[3] = 0;
		tab[4] = -1;
	}
	else if (mode == 4)
	{
		tab[0] = 0;
		tab[1] = 1;
		tab[2] = 0;
		tab[3] = -1;
	}
}
