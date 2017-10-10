/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 09:39:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 08:08:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ignore_whitespaces(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0' && (str[index] == ' '
			|| str[index] == '\t' || str[index] == '\n'))
	{
		index++;
	}
	return (str + index);
}

char	*ignore_word(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0' && (str[index] != ' '
				&& str[index] != '\t' && str[index] != '\n'))
	{
		index++;
	}
	return (str + index);
}

int		my_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0' && (str[length] != ' ' && str[length] != '\n'
			&& str[length] != '\t'))
	{
		length++;
	}
	return (length);
}

int		get_length_tot(char *tmp)
{
	int		length_word;

	length_word = 0;
	tmp = ignore_whitespaces(tmp);
	while (*tmp)
	{
		tmp = ignore_word(tmp);
		tmp = ignore_whitespaces(tmp);
		length_word++;
	}
	return (length_word);
}

char	**ft_split_whitespaces(char *str)
{
	int		length_tot;
	int		index[2];
	char	*tmp;
	char	**res;
	int		length_word;

	tmp = str;
	length_tot = get_length_tot(str);
	tmp = ignore_whitespaces(tmp);
	index[0] = 0;
	res = malloc(sizeof(char**) * (length_tot + 1));
	while (index[0] < length_tot)
	{
		index[1] = 0;
		length_word = my_strlen(tmp);
		res[index[0]] = malloc(sizeof(char *) * length_word + 1);
		while (index[1] < length_word)
			res[index[0]][index[1]++] = *(tmp++);
		res[index[0]][index[1]] = 0;
		index[0]++;
		tmp = ignore_whitespaces(tmp);
	}
	res[index[0]] = 0;
	return (res);
}
