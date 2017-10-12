/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:44:41 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/19 22:11:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strparse(char ***res, char *str, char c)
{
	int		nb_words;
	int 	index;
	int		place;

	index = 0;
	nb_words = 1;
	while (str[index] && (str[index] != c || ++nb_words) && ++index);
	if ((*res = (char **)malloc(sizeof(char *) * (nb_words + 1))) == NULL)
		return (-1);
	(*res)[nb_words] = 0;
	index = 0;
	while (index < nb_words)
	{
		place = ft_strcpos(str, c);
		if (place == -1)
			place = ft_strlen(str);
		(*res)[index] = ft_strnew(place);
		ft_strncpy((*res)[index], str, place);
		str = str + place + 1;
		index++;
	}
	return (nb_words);
}