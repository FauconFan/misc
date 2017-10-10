/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 14:27:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/13 18:51:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		match_recu(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 == 0 && *s2 == '*')
		return (1);
	if (*s1 == 0 || *s2 == 0)
		return (0);
	if (*s2 == '*')
	{
		while (*s2 == '*')
			s2++;
		if (*s2 == 0)
			return (1);
		while (*s1 != 0 && *s1 != *s2)
			s1++;
		if (*s1 == 0)
			return (0);
		while (match_recu(s1, s2) == 0)
		{
			s1++;
			while (*s1 != 0 && *s1 != *s2)
				s1++;
			if (*s1 == 0)
				return (0);
		}
		return (1);
	}
	if (*s1 != *s2)
		return (0);
	while(*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (match_recu(s1, s2));
}

int		match(char *s1, char *s2)
{
	if (s1 == 0 && s2 == 0)
		return (1);
	if (s1 == 0 || s2 == 0)
		return (0);
	return (match_recu(s1, s2));
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d\n", match(argv[1], argv[2]));
	}
	else
	{
		printf("Wrong format\n");
	}
	return (0);
}
