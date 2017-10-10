/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:20:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 14:00:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef	struct		s_perso
{
	int		age;
	char	*name;
	float	life;
	char	*profession;
}					t_perso;

char				*set_struct(char *str, t_perso *perso)
{
	int		index;
	int		length;
	char	*cpy;
	int		age_perso;

	index = 0;
	length = 0;
	cpy = str;
	age_perso = 0;
	while (*(cpy) != '|')
		age_perso = age_perso * 10 + *(cpy++) - '0';
	perso->age = age_perso;
	cpy++;
	str = cpy;
	while (cpy[length] != ';' && cpy[length] != '\0')
		length++;
	str = (char *)malloc(sizeof(char *) * (length + 1));
	while (index < length)
	{
		str[index] = *(cpy++);
		index++;
	}
	str[index] = '\0';
	perso->name = str;
	return (cpy);
}

t_perso				**ft_decrypt(char *str)
{
	int			length;
	int			index;
	char		*cpy;
	t_perso		**res;

	length = 0;
	cpy = str;
	while (*(cpy))
	{
		if (*(cpy) == '|')
		{
			length++;
		}
		cpy++;
	}
	res = (t_perso **)malloc(sizeof(t_perso **) * (length + 1));
	index = 0;
	while (index < length)
	{
		res[index] = (t_perso *)malloc(sizeof(t_perso *));
		str = set_struct(str, res[index++]);
		str++;
	}
	res[index] = 0;
	return (res);
}
