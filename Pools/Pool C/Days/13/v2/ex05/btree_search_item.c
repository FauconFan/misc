/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:14:43 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 13:18:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*tmp;

	if (root == 0)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp != 0)
		return (tmp);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	return (tmp);
}
