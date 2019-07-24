/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:16:57 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:05:09 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf) (void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, (*applyf));
	if (root->right)
		btree_apply_prefix(root->right, (*applyf));
}
