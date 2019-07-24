/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:35:45 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 16:58:24 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		build_line(t_dict *dict, char *line, int i)
{
	int j;

	j = 0;
	if (line[0] == '\0')
		return (0);
	dict[i].number = ft_atol(line);
	while (line[j] && line[j] != ':')
		j++;
	j++;
	while (line[j] && line[j] == ' ')
		j++;
	if (!(dict[i].literal = strdup_space(line + j)))
		return (1);
	return (0);
}

t_dict	*build_dict(char *buff)
{
	t_dict	*res;
	char	**split;
	int		nb_line;
	int		i;

	split = ft_split(buff, "\n");
	if ((nb_line = check_split(split)) < 0)
	{
		free_split(split);
		return (0);
	}
	if (!(res = (t_dict*)malloc(sizeof(t_dict) * (nb_line + 1))))
		return (NULL);
	i = 0;
	while (split[i])
	{
		build_line(res, split[i], i);
		i++;
	}
	res[i].number = 0;
	res[i].literal = 0;
	return (res);
}

int		read_dict(int fd, char *name, char *buff)
{
	int		rd;

	rd = read(fd, buff, 4096);
	if (rd < 0)
	{
		put_error_dict(3, name);
		return (1);
	}
	else if (rd >= 4096)
	{
		put_error_dict(4, NULL);
		return (1);
	}
	close(fd);
	return (0);
}

int		open_dict(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if ((fd = open("dict/numbers.dict", O_RDONLY)) < 3)
			return (put_error_dict(1, NULL));
	}
	else
	{
		if ((fd = open(av[2], O_RDONLY)) < 3)
			return (put_error_dict(2, av[2]));
	}
	return (fd);
}

t_dict	*init_dict(int ac, char **av)
{
	t_dict	*res;
	char	buff[4096];
	int		fd;

	res = NULL;
	if ((fd = open_dict(ac, av)) < 3)
		return (NULL);
	if (read_dict(fd, av[2], buff))
		return (NULL);
	if (!(res = build_dict(buff)))
		return (NULL);
	return (res);
}
