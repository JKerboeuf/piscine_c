/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:01:48 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/18 08:48:59 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*res;

	if (!(res = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	res->ac = ac;
	res->av = av;
	res->arg_i = 0;
	res->offset = 0;
	return (res);
}

int		main(int ac, char **av)
{
	int		err;
	int		first;
	t_data	*data;

	if (!(data = init_data(ac, av)))
		return (1);
	if ((data->arg_i = check_option(data)) < 0)
		return (1);
	if (data->ac == data->arg_i)
		if (read_stdin(data))
			err = 1;
	data->name = (data->ac > data->arg_i + 1 ? 1 : 0);
	first = 1;
	err = 0;
	while (data->arg_i < data->ac && av[data->arg_i])
	{
		if (read_file(data, first))
			err = 1;
		else
			first = 0;
		data->arg_i++;
	}
	return (err);
}
