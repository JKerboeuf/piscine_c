/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:08:23 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/25 11:39:10 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				build_data(char *file, t_data *data)
{
	int i;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!(data->map = ft_split(file + i, "\n")))
		return (put_error_int());
	return (0);
}

t_data			*init_data(char *file)
{
	t_data	*res;

	if (!file)
		return (NULL);
	if (!(res = (t_data*)malloc(sizeof(t_data))))
		return (put_error_ptr(file));
	res->map = NULL;
	res->line = 0;
	res->col = 0;
	res->sq_i = -1;
	res->sq_j = -1;
	res->sq_size = -1;
	if (check_file(file, res))
		return (free_data(res));
	if (build_data(file, res))
		return (free_data(res));
	free(file);
	return (res);
}
