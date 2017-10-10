/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:27:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 22:49:40 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_template_with_id(int id)
{
	if (id == 1)
		return ("o-o| |o-o");
	else if (id == 2)
		return ("/*\\* *\\*/");
	else if (id == 3)
		return ("ABAB BCBC");
	else if (id == 4)
		return ("ABCB BABC");
	else if (id == 5)
		return ("ABCB BCBA");
	return (0);
}

void	fill_str_with_template3(int x, char *str, char *template)
{
	int		index;

	if (x <= 1)
		*str = '\n';
	else if (x == 2)
	{
		*str = *template;
		*(str + 1) = '\n';
	}
	else if (x == 3)
	{
		*str = *template;
		*(str + 1) = *(template + 2);
		*(str + 2) = '\n';
	}
	else
	{
		index = 1;
		str[0] = *template;
		while (index <= x - 3)
			str[index++] = *(template + 1);
		str[index] = *(template + 2);
		str[index + 1] = '\n';
	}
}

char	*rush00(int x, int y, char *template)
{
	int		index;
	char	*res;

	res = (char *)malloc(sizeof(char *) * ((x + 1) * y + 1));
	if (res == NULL)
		return (NULL);
	index = 0;
	if (res == NULL)
		return (0);
	res[(x + 1) * y] = 0;
	if (y <= 0)
		return (res);
	fill_str_with_template3(x + 1, res, template);
	if (y <= 1)
		return (res);
	index = 1;
	while (index < y - 1)
	{
		fill_str_with_template3(x + 1, res + (index * (x + 1)), template + 3);
		index++;
	}
	if (y != 0)
		fill_str_with_template3(x + 1, res + (index * (x + 1)), template + 6);
	return (res);
}
