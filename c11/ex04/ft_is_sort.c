/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:11:27 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/16 12:08:09 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_croissant(int *tab, int length, int (*f) (int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_decroissant(int *tab, int length, int (*f) (int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	if (is_decroissant(tab, length, f) || is_croissant(tab, length, f))
		return (1);
	return (0);
}
