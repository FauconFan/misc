/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:51:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 10:19:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ignore_whitespaces(char *str, char *charset)
{
	int		index;
	int		index2;
	int		is_okay;

	index = 0;
	while (str[index])
	{
		is_okay = 0;
		index2 = 0;
		while (charset[index2])
		{
			if (str[index] == charset[index2])
				is_okay = 1;
			index2++;
		}
		if (is_okay == 0)
			break ;
		index++;
	}
	return (str + index);
}

char	*ignore_word(char *str, char *charset)
{
	int		index;
	int		index2;

	index = 0;
	while (str[index])
	{
		index2 = 0;
		while (charset[index2])
		{
			if (str[index] == charset[index2])
				return (str + index);
			index2++;
		}
		index++;
	}
	return (str + index);
}

int		my_strlen(char *str, char *charset)
{
	int		length;
	int		index2;

	length = 0;
	while (str[length])
	{
		index2 = 0;
		while (charset[index2])
		{
			if (str[length] == charset[index2])
				return (length);
			index2++;
		}
		length++;
	}
	return (length);
}

int		get_length_tot(char *tmp, char *charset)
{
	int		length_word;

	length_word = 0;
	tmp = ignore_whitespaces(tmp, charset);
	while (*tmp)
	{
		tmp = ignore_word(tmp, charset);
		tmp = ignore_whitespaces(tmp, charset);
		length_word++;
	}
	return (length_word);
}

char	**ft_split(char *str, char *charset)
{
	int		length_tot;
	int		index[2];
	char	*tmp;
	char	**res;
	int		length_word;

	tmp = str;
	length_tot = get_length_tot(str, charset);
	tmp = ignore_whitespaces(tmp, charset);
	index[0] = 0;
	res = malloc(sizeof(char**) * (length_tot + 1));
	while (index[0] < length_tot)
	{
		index[1] = 0;
		length_word = my_strlen(tmp, charset);
		res[index[0]] = malloc(sizeof(char *) * length_word + 1);
		while (index[1] < length_word)
			res[index[0]][index[1]++] = *(tmp++);
		res[index[0]][index[1]] = 0;
		index[0]++;
		tmp = ignore_whitespaces(tmp, charset);
	}
	res[index[0]] = 0;
	return (res);
}
