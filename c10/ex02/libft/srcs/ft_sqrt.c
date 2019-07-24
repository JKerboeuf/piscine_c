/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:03:16 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/16 10:21:52 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;
	int	j;

	res = 2;
	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (nb);
	j = nb;
	while (res <= j / 2)
	{
		if (res * res == nb)
			return (res);
		res++;
		j--;
	}
	return (0);
}
