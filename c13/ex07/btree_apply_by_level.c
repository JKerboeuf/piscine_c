/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:50:44 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:56:13 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_level(t_btree *root, int i,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!i && root)
		(*applyf)(root->item, i, 1);
	else if (root)
	{
		(*applyf)(root->item, i, 0);
		btree_level(root->left, i + 1, (*applyf));
		btree_level(root->right, i + 1, (*applyf));
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	else
		return (btree_level(root, 0, (*applyf)));
}
