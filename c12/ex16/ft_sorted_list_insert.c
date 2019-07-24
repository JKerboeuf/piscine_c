/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:51:17 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:18:47 by jukerboe         ###   ########.fr       */
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

static void	swap_data(t_list **elem1, t_list **elem2)
{
	void	*tmp;

	tmp = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp;
}

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!begin_list || !*begin_list)
		return ;
	while (i)
	{
		i = 0;
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, tmp->next->data) > 0)
			{
				swap_data(&tmp, &tmp->next);
				i = 1;
			}
			tmp = tmp->next;
		}
	}
}

void		ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, (*cmp));
}
