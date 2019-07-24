/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:52:13 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 14:52:41 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*res;

	res = ft_create_elem(data);
	if (res)
	{
		res->next = *begin_list;
		*begin_list = res;
	}
}

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list	*res;
	int		i;

	i = 0;
	if (!strs || size < 1)
		return (0);
	res = NULL;
	while (i < size)
	{
		ft_list_push_front(&res, strs[i]);
		i++;
	}
	return (res);
}
