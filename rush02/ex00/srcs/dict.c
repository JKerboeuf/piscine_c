/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:38:42 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 15:55:38 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		dict_size(t_dict *tab)
{
	int i;

	i = 0;
	while (tab[i].literal)
		i++;
	return (i);
}

int		free_dict(t_dict *dict)
{
	int i;

	i = 0;
	while (dict[i].literal)
	{
		free(dict[i].literal);
		i++;
	}
	free(dict);
	return (1);
}

int		verif_dict(t_dict *dict)
{
	int	i;
	int	j;
	int size;

	if (!dict[1].literal)
		return (0);
	i = 0;
	while (dict[i].literal)
	{
		j = i + 1;
		while (dict[j].literal)
		{
			if (dict[j].number == dict[i].number)
				return (put_error_split(2, dict[j].number));
			j++;
		}
		i++;
	}
	if ((size = dict_size(dict)) < 32)
		return (put_error_split(3, 32 - size));
	return (0);
}

void	swap_dict(ULL *nb_a, ULL *nb_b, char **lit_a, char **lit_b)
{
	ULL		nb_tmp;
	char	*lit_tmp;

	nb_tmp = *nb_a;
	*nb_a = *nb_b;
	*nb_b = nb_tmp;
	lit_tmp = *lit_a;
	*lit_a = *lit_b;
	*lit_b = lit_tmp;
}

void	sort_dict(t_dict *dict)
{
	int		i;
	int		j;

	i = 0;
	while (dict[i].literal)
		i++;
	while (i > 1)
	{
		j = 0;
		while (j < i - 1)
		{
			if (dict[j + 1].number < dict[j].number)
			{
				swap_dict(&dict[j + 1].number, &dict[j].number,
						&dict[j + 1].literal, &dict[j].literal);
			}
			j++;
		}
		i--;
	}
}
