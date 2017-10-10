/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:25:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 13:39:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	apply_by_level_recu(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem),
		int level, int first_elem)
{
	if (root == 0)
		return ;
	applyf(root->item, level, first_elem);
	apply_by_level_recu(root->left, applyf, level + 1, first_elem);
	apply_by_level_recu(root->right, applyf, level + 1, 0);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	apply_by_level_recu(root, applyf, 0, 1);
}
