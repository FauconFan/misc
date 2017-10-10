/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:55:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 16:21:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimate_fight.h"

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	putstr(char *s)
{
	int		length;
	char	*cpy;

	cpy = s;
	length = 0;
	while (*(cpy++))
		length++;
	write(1, s, length);
}

int		get_value(char *s)
{
	if (my_strcmp(s, KICK1))
		return (13);
	if (my_strcmp(s, KICK2))
		return (3);
	if (my_strcmp(s, KICK3))
		return (18);
	if (my_strcmp(s, KICK4))
		return (9);
	if (my_strcmp(s, KICK5))
		return (11);
	if (my_strcmp(s, KICK6))
		return (13);
	if (my_strcmp(s, KICK7))
		return (8);
	if (my_strcmp(s, KICK8))
		return (6);
	if (my_strcmp(s, KICK9))
		return (11);
	if (my_strcmp(s, KICK10))
		return (9);
	if (my_strcmp(s, KICK11))
		return (18);
	if (my_strcmp(s, KICK12))
		return (10);
	return (0);
}

void	ft_fight(t_perso *attacker, t_perso *defenser, char *s)
{
	if (defenser->life > 0)
	{
		defenser->life -= get_value(s);
		putstr(attacker->name);
		putstr(" does ");
		putstr(s);
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
