/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:01:16 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/15 18:29:02 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_atoi(char *str)
{
	int				res;
	int				neg;
	unsigned int	i;

	res = 0;
	neg = 1;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == ' ' || str[i] == '\v' || str[i] == '\r') &&
			str[i] != '\0')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		res *= 10;
		res += (int)str[i] - 48;
		i++;
	}
	return (res * neg);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	do_op(int a, int b, int i)
{
	int	(*ope[5])(int, int);

	ope[0] = add;
	ope[1] = sub;
	ope[2] = mul;
	ope[3] = div;
	ope[4] = mod;
	if ((i == 3 || i == 4) && b == 0)
	{
		if (i == 3)
			ft_putstr("Stop : division by zero");
		if (i == 4)
			ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(ope[i](a, b));
}

int		main(int ac, char **av)
{
	int	a;
	int b;

	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		if (!ft_strcmp(av[2], "+"))
			do_op(a, b, 0);
		else if (!ft_strcmp(av[2], "-"))
			do_op(a, b, 1);
		else if (!ft_strcmp(av[2], "*"))
			do_op(a, b, 2);
		else if (!ft_strcmp(av[2], "/"))
			do_op(a, b, 3);
		else if (!ft_strcmp(av[2], "%"))
			do_op(a, b, 4);
		else
			ft_putnbr(0);
		ft_putchar('\n');
	}
	return (0);
}
