/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:02:30 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/05 08:06:13 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	minimize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
}

int		test_char(char c)
{
	if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') &&
			(c < 'a' || c > 'z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 1;
	minimize(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && !test_char(str[i - 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
