/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:41:18 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 16:11:07 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		main(int ac, char **av)
{
	ULL		nbr;
	t_dict	*dict;

	if (check_args(ac, av))
		return (1);
	nbr = ft_atol(av[1]);
	if (!(dict = init_dict(ac, av)))
		return (1);
	if (verif_dict(dict))
		return (free_dict(dict));
	sort_dict(dict);
	put_translate(nbr, dict);
	ft_putchar('\n');
	free_dict(dict);
	return (0);
}
