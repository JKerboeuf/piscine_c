/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:46:10 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:12:10 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *tmp;

	tmp = *root;
	if (!*root)
		*root = btree_create_node(item);
	else if (cmpf(item, tmp->item) < 0)
	{
		if (tmp->left)
			btree_insert_data(&tmp->left, item, cmpf);
		else
			tmp->left = btree_create_node(item);
	}
	else
	{
		if (tmp->right)
			btree_insert_data(&tmp->right, item, cmpf);
		else
			tmp->right = btree_create_node(item);
	}
}
