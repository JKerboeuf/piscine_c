/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:03:39 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 11:52:46 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct) (void *))
{
	if (begin_list)
	{
		ft_list_clear(begin_list->next, (*free_fct));
		free_fct(begin_list->data);
		free(begin_list);
	}
}
