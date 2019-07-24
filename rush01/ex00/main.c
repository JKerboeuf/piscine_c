/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 08:30:20 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:05:23 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	display(int *map)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr(map[i]);
		if ((i + 1) % 4 != 0)
			ft_putchar(' ');
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int *lim;
	int size;
	int *res;

	if (check_error(ac, av))
		return (put_error("Error\n"));
	if ((size = get_len(av[1])) < 0)
		return (put_error("Error\n"));
	if (!(lim = init_lim(av[1])))
		return (put_error("Error\n"));
	res = init_map(4);
	if (ft_fill(res, lim, 0))
		display(res);
	else
		return (put_error("Error\n"));
	return (0);
}
