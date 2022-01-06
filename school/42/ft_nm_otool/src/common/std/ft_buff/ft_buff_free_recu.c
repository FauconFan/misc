/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_free_recu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:02:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 10:03:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_buff_free_recu(t_buff_inner *head)
{
	if (head)
	{
		ft_buff_free_recu(head->next);
		free(head->buff);
		free(head);
	}
}
