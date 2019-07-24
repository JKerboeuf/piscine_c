/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:41:28 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 12:11:55 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
