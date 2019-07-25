/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:55:44 by dbenzimr          #+#    #+#             */
/*   Updated: 2019/07/24 10:06:28 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		test_lign_col(t_data *data, int y, int x, int i)
{
	int j;

	j = i;
	while (y + j != y && data->map[y + j][x + i] != data->rules[1])
		j--;
	if (y + j != y || data->map[y + j][x + i] == data->rules[1])
		return (0);
	j = i;
	while (x + j != x && data->map[y + i][x + j] != data->rules[1])
		j--;
	if (x + j != x || data->map[y + i][x + j] == data->rules[1])
		return (0);
	return (1);
}

void	test_square(t_data *data, int y, int x)
{
	int i;
	int length;

	i = 1;
	while (y + i < data->line && x + i < data->col &&
			test_lign_col(data, y, x, i))
		i++;
	length = i;
	if (length > data->sq_size)
	{
		data->sq_size = length;
		data->sq_i = y;
		data->sq_j = x;
	}
}

void	hunt(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->line - 1)
	{
		x = 0;
		while (x < data->col - 1)
		{
			if (data->map[y + 1][x + 1] != data->rules[1] &&
					data->map[y + 1][x] != data->rules[1] &&
					data->map[y][x + 1] != data->rules[1] &&
					data->map[y][x] != data->rules[1])
				test_square(data, y, x);
			x++;
		}
		y++;
	}
	return ;
}

void	insert_result(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->sq_size)
	{
		j = 0;
		while (j < data->sq_size && data->map[data->sq_i + i][data->sq_j + j])
		{
			data->map[data->sq_i + i][data->sq_j + j] = data->rules[2];
			j++;
		}
		i++;
	}
}

int		min_square(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->rules[0])
			{
				data->sq_size = 1;
				data->sq_i = i;
				data->sq_j = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
