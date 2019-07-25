/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:05:59 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/24 16:15:17 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_bsq(t_data *data)
{
	unsigned int i;

	i = 0;
	while (data->map[i])
		ft_putstrnl(data->map[i++]);
}

void	*put_error_ptr(char *to_free)
{
	ft_putstrnl_fd("map error", 2);
	if (to_free)
		free(to_free);
	return (NULL);
}

int		put_error_int(void)
{
	ft_putstrnl_fd("map error", 2);
	return (1);
}
