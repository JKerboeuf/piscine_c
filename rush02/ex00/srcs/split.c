/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 08:57:46 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 09:07:59 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		check_line(char *line)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == ':')
	{
		i++;
		b = 1;
	}
	while (line[i] && line[i] == ' ' && b)
		i++;
	while (line[i] && line[i] >= 32 && line[i] <= 126 && b)
		i++;
	if (line[i] != '\0' || !b || line[i - 1] == ' ' || line[i - 1] == ':')
		return (1);
	return (0);
}

int		check_split(char **split)
{
	int i;
	int	nb_line;

	i = 0;
	nb_line = 0;
	while (split[i])
	{
		if (check_line(split[i]))
			return (put_error_split(-1, i + 1));
		if (split[i][0])
			nb_line++;
		i++;
	}
	return (nb_line);
}

int		free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	while (--i)
		free(split[i]);
	free(split);
	return (1);
}
