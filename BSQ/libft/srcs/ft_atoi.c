/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:39:42 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/16 10:21:25 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
