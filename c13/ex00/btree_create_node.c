/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:57:26 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 13:56:42 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*res;

	if (!(res = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	res->item = item;
	res->left = NULL;
	res->right = NULL;
	return (res);
}
