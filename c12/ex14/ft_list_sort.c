/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:47:29 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:17:56 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	swap_data(t_list **elem1, t_list **elem2)
{
	void	*tmp;

	tmp = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp;
}

void		ft_list_sort(t_list **begin_list, int (*cmp)())
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
