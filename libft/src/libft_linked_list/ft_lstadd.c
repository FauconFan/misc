/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:24:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 18:48:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst == 0)
		return ;
	else if (*alst == 0)
	{
		*alst = new;
		new->next = 0;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
