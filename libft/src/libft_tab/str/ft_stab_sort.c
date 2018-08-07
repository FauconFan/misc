/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:38:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 16:39:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stab_sort(char **tab, int (*f)(char *, char *))
{
	ft_vtab_sort((void **)tab, (int (*)(void *, void *))f);
}
