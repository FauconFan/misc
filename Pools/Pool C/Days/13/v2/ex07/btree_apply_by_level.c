/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:25:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 20:00:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	apply_by_level_recu(t_btree *root,
		t_data *data, int remaining_level, int first_elem)
{
	if (root == 0)
		return ;
	if (remaining_level == 0)
	{
		data->applyf(root->item, data->level, first_elem);
		return ;
	}
	apply_by_level_recu(root->left, data, remaining_level - 1, first_elem);
	apply_by_level_recu(root->right, data, remaining_level - 1, 0);
}

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

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		size_tree;
	int		index;
	t_data	*data;

	size_tree = btree_level_count(root);
	if ((data = (t_data *)malloc(sizeof(t_data *))) == 0)
		return ;
	data->applyf = applyf;
	index = 0;
	while (index <= size_tree)
	{
		data->level = index;
		apply_by_level_recu(root, data, index, 1);
		index++;
	}
	free(data);
}
