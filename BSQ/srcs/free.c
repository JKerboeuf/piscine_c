/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:10:11 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/24 10:39:13 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		free_split(char **split)
{
	int i;

	i = 0;
	if (!split || !*split)
		return (1);
	while (split[i])
		i++;
	while (--i != -1)
	{
		if (split[i])
			free(split[i]);
	}
	free(split);
	return (1);
}

void	*free_data(t_data *data)
{
	if (data && data->map)
		free_split(data->map);
	if (data)
		free(data);
	return (NULL);
}
