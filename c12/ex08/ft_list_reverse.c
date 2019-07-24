/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:32:50 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:21:02 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_push_front(t_list **begin_list, t_list *elem)
{
	if (elem)
	{
		elem->next = *begin_list;
		*begin_list = elem;
	}
}

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*head;
	t_list	*tmp;
	int		i;

	if (!begin_list || !*begin_list)
		return ;
	i = 0;
	curr = *begin_list;
	head = 0;
	while (curr)
	{
		tmp = curr->next;
		ft_list_push_front(&head, curr);
		curr = tmp;
	}
	*begin_list = head;
}
