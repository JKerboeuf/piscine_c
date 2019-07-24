/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:35:26 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:05:36 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf) (void *))
{
	if (root->left)
		btree_apply_infix(root->left, (*applyf));
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, (*applyf));
}
