/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:51:49 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 17:02:19 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*strdup_space(char *str)
{
	char	**split;
	char	*res;
	int		len;

	if (!(split = ft_split(str, " ")))
		return (NULL);
	len = 0;
	while (split[len])
		len++;
	if (!(res = ft_strjoin(len, split, " ")))
	{
		free_split(split);
		return (NULL);
	}
	free_split(split);
	return (res);
}
