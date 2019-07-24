/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:35:25 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 16:18:11 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		test_exist(ULL nbr, t_dict *dict)
{
	int i;

	i = 0;
	while (dict[i].literal)
	{
		if (dict[i].number == nbr)
		{
			if (nbr >= 100)
			{
				ft_putstr(dict[1].literal);
				write(1, " ", 1);
			}
			ft_putstr(dict[i].literal);
			return (1);
		}
		i++;
	}
	return (0);
}

void	put_translate(ULL nbr, t_dict *dict)
{
	int i;
	int size;

	size = dict_size(dict);
	if (nbr == 0)
		return (ft_putstr(dict[0].literal));
	if (test_exist(nbr, dict))
		return ;
	i = size - 1;
	while (i && (nbr / dict[i].number == 0))
		i--;
	if (nbr > 100)
	{
		put_translate(nbr / dict[i].number, dict);
		write(1, " ", 1);
	}
	ft_putstr(dict[i].literal);
	if (nbr % dict[i].number != 0)
	{
		write(1, " ", 1);
		put_translate(nbr % dict[i].number, dict);
	}
}
