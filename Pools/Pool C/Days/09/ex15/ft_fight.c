/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:28:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 16:31:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fight.h"

int		my_strlen(char *s)
{
	int		length;

	length = 0;
	while (*(s++))
		length++;
	return (length);
}

void	putstr(char *s)
{
	write(1, s, my_strlen(s));
}

void	putkick(int value)
{
	if (value == KICK)
		putstr("a judo kick");
	else if (value == PUNCH)
		putstr("a judo punch");
	else if (value == HEADBUTT)
		putstr("a judo headbutt");
}

void	ft_fight(t_perso *attacker, t_perso *defenser, int value)
{
	if (defenser->life > 0)
	{
		defenser->life -= value;
		putstr(attacker->name);
		putstr(" does ");
		putkick(value);
		putstr(" on ");
		putstr(defenser->name);
		putstr(".\n");
		if (defenser->life <= 0)
		{
			defenser->life = 0;
			putstr(defenser->name);
			putstr(" is dead.\n");
		}
	}
}
