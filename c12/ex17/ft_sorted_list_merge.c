/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:54:44 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:20:08 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *tmp;

	if (*begin_list1)
	{
		tmp = *begin_list1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
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

void		ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, (*cmp));
}
