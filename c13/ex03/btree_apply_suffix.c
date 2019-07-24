/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:43:09 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:06:21 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf) (void *))
{
	if (root->left)
		btree_apply_suffix(root->left, (*applyf));
	if (root->right)
		btree_apply_suffix(root->right, (*applyf));
	applyf(root->item);
}
