/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:53:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 11:23:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define ALERT "Alert!!!\n"
#define WORD1 "president"
#define WORD2 "attack"
#define WORD3 "powers"

int		my_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
		{
			return (0);
		}
		index++;
	}
	if (s1[index] == ' ' || s1[index] == '\t' || s1[index] == '\n')
		return (0);
	return (s1[index] - s2[index]);
}

int		my_strlen(char *s)
{
	int		length;

	length = 0;
	while (s[length] != '\0' && s[length] != ' '
			&& s[length] != '\n' && s[length] != '\t')
		length++;
	return (length);
}

char	*adapt_str(char *s1)
{
	int		index;
	int		letter;

	index = 0;
	while (s1[index] != '\0')
	{
		if (s1[index] != ' ' && s1[index] != '\n' && s1[index] != '\t')
		{
			break ;
		}
		index++;
	}
	letter = 0;
	while (s1[index + letter] != '\0')
	{
		if (s1[index + letter] >= 'A' && s1[index + letter] <= 'Z')
		{
			s1[index + letter] = s1[index + letter] + 'a' - 'A';
		}
		letter++;
	}
	return (s1 + index);
}

int		check_word(char *str, char *word)
{
	if (my_strcmp(str, word) == 0)
	{
		str = str + my_strlen(str);
		str = adapt_str(str);
		if (*str != '\0')
		{
			if (check_word(str, WORD1) == 1
				|| check_word(str, WORD2) == 1
				|| check_word(str, WORD3) == 1)
				return (1);
			return (0);
		}
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		index;
	char	*tmp;

	index = 1;
	while (index < argc)
	{
		argv[index] = adapt_str(argv[index]);
		if (check_word(argv[index], WORD1) == 1
				|| check_word(argv[index], WORD2) == 1
				|| check_word(argv[index], WORD3) == 1)
		{
			write(1, ALERT, my_strlen(ALERT) + 1);
			return (0);
		}
		index++;
	}
	return (0);
}
