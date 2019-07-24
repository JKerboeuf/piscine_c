/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:41:06 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:12:21 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_left(int *tab, int num, int pos)
{
	int check;
	int x;

	check = 0;
	x = pos;
	while (x < pos + 4)
	{
		if (check < tab[x])
		{
			check = tab[x];
			num--;
		}
		x++;
	}
	return (num);
}

int	check_right(int *tab, int num, int pos)
{
	int check;
	int x;

	check = 0;
	x = pos;
	while (x > pos - 4)
	{
		if (check < tab[x])
		{
			check = tab[x];
			num--;
		}
		x--;
	}
	return (num);
}

int	check_down(int *tab, int num, int pos)
{
	int check;
	int x;

	check = 0;
	x = pos;
	while (x >= pos - 12)
	{
		if (check < tab[x])
		{
			check = tab[x];
			num--;
		}
		x -= 4;
	}
	return (num);
}

int	check_up(int *tab, int num, int pos)
{
	int check;
	int x;

	check = 0;
	x = pos;
	while (x <= pos + 12)
	{
		if (check < tab[x])
		{
			check = tab[x];
			num--;
		}
		x += 4;
	}
	return (num);
}

int	check_valid(int *tab, int *cote)
{
	int x;

	x = -1;
	while (++x < 4)
		if (check_up(tab, cote[x], x))
			return (0);
	while (++x < 8)
		if (check_down(tab, cote[x], x + 8))
			return (0);
	while (++x < 12)
		if (check_left(tab, cote[x], (x - 8) * 4))
			return (0);
	if (check_right(tab, cote[12], 3))
		return (0);
	if (check_right(tab, cote[13], 7))
		return (0);
	if (check_right(tab, cote[14], 11))
		return (0);
	if (check_right(tab, cote[15], 15))
		return (0);
	return (1);
}
