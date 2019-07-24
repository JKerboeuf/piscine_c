/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:14:57 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 11:54:13 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	tmp = begin_list;
	while (tmp && i != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp && i == nbr)
		return (tmp);
	return (0);
}
