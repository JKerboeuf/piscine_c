/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:26:27 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/06 14:27:01 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	unsigned int	res;

	if (nb < 2)
		return (2);
	else
		res = nb;
	while (res < (unsigned int)(2 * nb))
	{
		if (ft_is_prime(res))
			return (res);
		res++;
	}
	return (0);
}
