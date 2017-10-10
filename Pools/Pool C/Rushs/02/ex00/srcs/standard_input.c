/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:53:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 22:48:25 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "functions.h"

#define BUF_LINE 80

char	*get_standard_input(void)
{
	char	*tmp;
	char	*tmp2;
	char	buffer;
	int		index;

	tmp = (char *)malloc(sizeof(char *) * (BUF_LINE + 1));
	if (tmp == NULL)
		return (NULL);
	index = 0;
	while (read(0, &buffer, 1) == 1)
	{
		if (index == ft_strlen(tmp))
		{
			tmp2 = (char *)malloc(sizeof(char *) * (2 * ft_strlen(tmp)) + 1);
			if (tmp2 == NULL)
				return (0);
			ft_strcpy(tmp2, tmp);
			free(tmp);
			tmp = tmp2;
			tmp2 = 0;
		}
		tmp[index] = buffer;
		index++;
	}
	return (tmp);
}
