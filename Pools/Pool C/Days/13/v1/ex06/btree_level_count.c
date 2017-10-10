/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:20:23 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 13:23:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int		max_left;
	int		max_right;

	if (root == 0)
		return (0);
	max_right = 1 + btree_level_count(root->right);
	max_left = 1 + btree_level_count(root->left);
	if (max_left > max_right)
		return (max_left);
	return (max_right);
}
