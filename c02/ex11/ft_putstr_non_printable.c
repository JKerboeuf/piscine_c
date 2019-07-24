/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:16:40 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/10 08:55:51 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(int c)
{
	int i;
	int mod;
	int hex[3];

	i = 0;
	write(1, "\\", 1);
	if (c < 16 && c >= 0)
		write(1, "0", 1);
	else if (c < 0)
		c += 256;
	while (c != 0)
	{
		mod = 0;
		mod = c % 16;
		if (mod < 10)
			hex[i] = mod + 48;
		else
			hex[i] = mod + 87;
		i++;
		c /= 16;
	}
	while (--i >= 0)
		write(1, &hex[i], 1);
}

int		is_non_print(char c)
{
	if (c < 32 || c > 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (!is_non_print(str[i]))
			write(1, &str[i], 1);
		else
			print_hexa((int)str[i]);
		i++;
	}
}
