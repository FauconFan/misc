/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:39:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 08:10:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		my_strlen(char *s)
{
	int		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

int		get_size(int argc, char **argv)
{
	int		index;
	int		length;

	index = 1;
	length = 0;
	while (index < argc)
	{
		length += my_strlen(argv[index]);
		index++;
	}
	return (length);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		index[3];
	char	*str;
	int		length_tot;

	length_tot = get_size(argc, argv);
	str = (char*)malloc(length_tot + 1);
	index[0] = 0;
	index[1] = 0;
	index[2] = 1;
	while (index[0] < length_tot)
	{
		if (argv[index[2]][index[1]] == '\0')
		{
			str[index[0]] = '\n';
			index[1] = 0;
			index[2]++;
		}
		else
			str[index[0]] = argv[index[2]][index[1]++];
		index[0]++;
	}
	str[index[0]] = '\0';
	return (str);
}
