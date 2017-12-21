/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_from_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:23:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 08:33:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*read_from_input(void)
{
	char	*res;
	char	*tamp;
	char	c;
	size_t	size;

	size = 0;
	res = ft_strnew(size);
	while (1)
	{
		if (read(0, &c, 1) == -1)
			ft_die("read aborted");
		if (c == '\n')
			break ;
		tamp = ft_strndup(res, size);
		tamp[size] = c;
		size++;
		free(res);
		res = tamp;
	}
	return (res);
}
