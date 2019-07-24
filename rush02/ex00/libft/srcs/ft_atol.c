/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:58:45 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 10:15:35 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_atol(char *str)
{
	unsigned long long	res;
	int					i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (res);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
