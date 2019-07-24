/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:07:18 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/15 16:10:45 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f) (char*))
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < length)
	{
		if (f(tab[i]))
			res++;
		i++;
	}
	return (res);
}
