/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:31:08 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/03 08:24:32 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int j)
{
	int	mem;

	mem = tab[j + 1];
	tab[j + 1] = tab[j];
	tab[j] = mem;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j + 1] < tab[j] && j < size)
				swap(tab, j);
			j++;
		}
		i--;
	}
}
