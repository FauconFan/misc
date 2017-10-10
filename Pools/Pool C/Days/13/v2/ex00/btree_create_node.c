/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:19:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 11:21:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree	*res;

	res = (t_btree *)malloc(sizeof(t_btree *));
	res->right = 0;
	res->left = 0;
	res->item = item;
	return (res);
}
