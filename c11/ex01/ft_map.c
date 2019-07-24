/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:56:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/15 16:02:53 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	*res;
	int	i;

	i = 0;
	if (!(res = (int*)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
