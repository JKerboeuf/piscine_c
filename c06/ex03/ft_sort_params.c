/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:25:35 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/08 11:41:25 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print_params(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	(void)ac;
	i = 1;
	while (av[i])
		i++;
	while (i > 1)
	{
		j = 1;
		while (j < i - 1)
		{
			if (ft_strcmp(av[j + 1], av[j]) < 0)
			{
				tmp = av[j + 1];
				av[j + 1] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i--;
	}
	ft_print_params(av);
	return (0);
}
