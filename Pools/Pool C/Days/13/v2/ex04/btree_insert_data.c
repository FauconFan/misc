/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:06:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 19:25:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *data,
		int (*cmpf)(void *, void *))
{
	if (root == 0)
		return ;
	if (*root == 0)
	{
		*root = btree_create_node(data);
		return ;
	}
	if (cmpf(data, (*root)->item) >= 0)
	{
		btree_insert_data((&((*root)->right)), data, cmpf);
		return ;
	}
	btree_insert_data((&((*root)->left)), data, cmpf);
}
