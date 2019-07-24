/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:13:43 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 10:20:57 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void *tmp;

	tmp = 0;
	if (root)
	{
		tmp = btree_search_item(root->left, data_ref, cmpf);
		if (!tmp && cmpf(data_ref, root->item) == 0)
			tmp = root->item;
		if (!tmp)
			tmp = btree_search_item(root->right, data_ref, cmpf);
	}
	return (tmp);
}
