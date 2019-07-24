/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:29:47 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/19 15:08:44 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	size(t_list *begin_list)
{
	int		res;
	t_list	*tmp;

	res = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		res++;
	}
	return (res);
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	void	*tmp;
	t_list	*list;
	int		i;
	int		j;
	int		len;

	len = size(begin_list);
	list = begin_list;
	i = 0;
	while (i < len - 1)
	{
		j = i;
		list = begin_list;
		while (list && list->next && j < len - 1)
		{
			tmp = list->data;
			list->data = list->next->data;
			list->next->data = tmp;
			list = list->next;
			j++;
		}
		i++;
	}
}
