/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:45:55 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:17:52 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_len(char *av)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] >= '1' && av[i] <= '4')
			res++;
		i++;
	}
	if (res % 4 != 0 || res != 16)
		return (-1);
	return (res / 4);
}

int	*init_lim(char *av)
{
	int *res;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(res = (int*)malloc(sizeof(int) * 17)))
		return (NULL);
	while (i < 16)
	{
		if (av[j] - '0' > 4)
		{
			free(res);
			return (NULL);
		}
		res[i] = av[j] - '0';
		i++;
		j += 2;
	}
	res[i] = 0;
	return (res);
}

int	*init_map(int size)
{
	int	*res;
	int	i;

	if (!(res = (int*)malloc(sizeof(int) * (size * 4 + 1))))
		return (NULL);
	i = 0;
	while (i < size * 4)
	{
		res[i] = 0;
		i++;
	}
	res[i] = 0;
	return (res);
}
