/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:54:11 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/24 12:05:44 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fetou(t_data *data)
{
	hunt(data);
	if (data->sq_size > 0)
		insert_result(data);
	else if (min_square(data))
		insert_result(data);
	print_bsq(data);
}

int		main(int ac, char **av)
{
	int		i;
	t_data	*data;

	i = 1;
	if (ac == 1)
	{
		if ((data = init_data(read_stdin())))
			fetou(data);
		free_data(data);
	}
	else
	{
		while (i < ac)
		{
			if ((data = init_data(read_file(av[i]))))
				fetou(data);
			if (i < ac - 1)
				ft_putchar('\n');
			free_data(data);
			i++;
		}
	}
	return (0);
}
