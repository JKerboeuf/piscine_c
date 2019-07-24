/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:35:56 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:17:17 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	put_error(char *str)
{
	while (*str)
		write(1, str++, 1);
	return (1);
}

int	check_error(int ac, char **av)
{
	int i;

	if (ac != 2)
		return (1);
	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] < '1' || av[1][i] > '4') && i % 2 == 0)
			return (1);
		else if (av[1][i] != ' ' && i % 2 != 0)
			return (1);
		i++;
	}
	if (av[1][i] == '\0' && av[1][i - 1] == ' ')
		return (1);
	return (0);
}
