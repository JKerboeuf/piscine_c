/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:05:11 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:10:20 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_free(t_list **prev, t_list **curr, void (*f_fct) (void *))
{
	t_list	*tmp;

	tmp = *curr;
	if (!prev)
	{
		*curr = (*curr)->next;
		(*f_fct)(tmp->data);
		free(tmp);
	}
	else
	{
		(*prev)->next = tmp->next;
		*curr = (*curr)->next;
		(*f_fct)(tmp->data);
		free(tmp);
	}
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*prev;
	int		b;

	b = 0;
	prev = *begin_list;
	tmp = *begin_list;
	while (tmp)
	{
		if (!b && (*cmp)(tmp->data, data_ref) == 0)
		{
			*begin_list = tmp->next;
			ft_free(0, &tmp, (*free_fct));
		}
		else if ((*cmp)(tmp->data, data_ref) == 0)
			ft_free(&prev, &tmp, (*free_fct));
		else
		{
			prev = tmp;
			tmp = tmp->next;
			b = 1;
		}
	}
}
