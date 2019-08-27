/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:34:10 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:24:03 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

static size_t	count_words(char *s, char c)
{
	size_t		words;

	words = 0;
	while (*s && *s == c)
		s++;
	if (*s != c && *s)
		words = 1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			words++;
		s++;
	}
	return (words);
}

char			**my_strsplit(char const *s, char c)
{
	char		**new;
	size_t		start;
	size_t		tmp;
	size_t		words;

	if (!s || !c)
		return (NULL);
	start = 0;
	tmp = 0;
	words = count_words((char*)s, c);
	if ((new = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		my_protect_malloc();
	while (s[start])
	{
		while (s[start] == c && c)
			start++;
		tmp = start;
		while (s[tmp] != c && s[tmp])
			tmp++;
		if (s[tmp] || start != tmp)
			*(new++) = my_strsub(s, start, tmp - start);
		start = tmp;
	}
	*new = NULL;
	return (new - words);
}
