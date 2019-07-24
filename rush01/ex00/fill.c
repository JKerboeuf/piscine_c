/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:42:36 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:08:28 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	isposable(int *tab, int pos, int i)
{
	int x;
	int y;
	int p;

	x = pos % 4;
	y = pos / 4;
	p = 0;
	while (p < 4)
	{
		if (tab[p + y * 4] == i)
			return (0);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		if (tab[x + p * 4] == i)
			return (0);
		p++;
	}
	return (1);
}

int	ft_fill(int *tab, int *cote, int pos)
{
	int i;

	if (pos == 16)
	{
		if (check_valid(tab, cote))
			return (1);
		return (0);
	}
	if (tab[pos])
	{
		if (ft_fill(tab, cote, pos + 1))
			return (1);
		return (0);
	}
	i = 0;
	while (++i <= 4)
		if (isposable(tab, pos, i))
		{
			tab[pos] = i;
			if (ft_fill(tab, cote, pos + 1))
				return (1);
			tab[pos] = 0;
		}
	return (0);
}
