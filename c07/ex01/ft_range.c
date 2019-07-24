/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:28:02 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/06 19:51:42 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (0);
	if (!(res = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	i = 0;
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	res[i] = 0;
	return (res);
}
