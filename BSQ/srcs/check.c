/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:10:22 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/25 11:39:20 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_first_line(char *line, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9' && line[i] != '\n')
		i++;
	while (line[i + j] && line[i + j] != '\n')
		j++;
	if (j != 3 || i == 0)
		return (put_error_int());
	data->line = ft_atoi(line);
	data->rules[0] = line[i++];
	data->rules[1] = line[i++];
	data->rules[2] = line[i++];
	return (0);
}

int		is_in_rules(char c, t_data *data)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (data->rules[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_line(char *line, t_data *data)
{
	int i;

	if (data->col && ft_strlen(line) != (unsigned int)data->col)
		return (put_error_int());
	data->col = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (!is_in_rules(line[i], data))
			return (put_error_int());
		i++;
	}
	return (0);
}

int		check_file(char *file, t_data *data)
{
	int		i;
	char	**split;

	split = ft_split(file, "\n");
	if (check_first_line(split[0], data))
		return (free_split(split));
	i = 1;
	while (split[i])
	{
		if (check_line(split[i], data))
			return (free_split(split));
		i++;
	}
	if (i - 1 != data->line)
	{
		free_split(split);
		return (put_error_int());
	}
	free_split(split);
	return (0);
}
