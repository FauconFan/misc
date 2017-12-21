/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:56:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 19:17:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*concat_dir_str(char *s1, char *s2)
{
	char	*res;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (s1[l1 - 1] == '/')
	{
		res = ft_strnew(l1 + l2);
		ft_strncpy(res, s1, l1);
		ft_strncpy(res + l1, s2, l2);
	}
	else
	{
		res = ft_strnew(l1 + l2 + 1);
		ft_strncpy(res, s1, l1);
		res[l1] = '/';
		ft_strncpy(res + l1 + 1, s2, l2);
	}
	return (res);
}
