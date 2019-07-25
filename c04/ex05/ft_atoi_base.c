/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:05:43 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/25 14:15:40 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && c != base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if ((base[i] < 33 || base[i] > 126) && base[i] == 43 && base[i] == 45)
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

int	ft_atoi_base(char *str, char *base)
{
	int				res;
	int				neg;
	unsigned int	i;
	int				size;

	res = 0;
	neg = 1;
	i = 0;
	if ((size = check_base(base)) < 2)
		return (0);
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == ' ' || str[i] == '\v' || str[i] == '\r') &&
			str[i] != '\0')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (is_in_base(str[i], base))
		res = (res * size) + get_index(str[i++], base);
	return (res * neg);
}
