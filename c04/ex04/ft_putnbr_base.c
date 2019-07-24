/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:31:20 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 15:00:40 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if ((base[i] < '0' || base[i] > '9') && (base[i] < 'a' || base[i] > 'z')
			&& (base[i] < 'A' || base[i] > 'Z'))
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr(long nbr, char *base)
{
	int	size;
	int	res[1000];
	int	i;

	i = 0;
	size = 0;
	if (!base[1] || !(size = check_base(base)))
		return ;
	if (nbr == 0)
		ft_putchar(base[0]);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr)
	{
		res[i] = nbr % size;
		nbr /= size;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[res[i]]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_putnbr((long)nbr, base);
}
