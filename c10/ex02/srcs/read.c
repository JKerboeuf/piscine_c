/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:34:27 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/18 17:32:36 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <stdio.h>

void	display_name(char *name, int first)
{
	if (!first)
		ft_putstr_fd("\n", 1);
	ft_putstr_fd("==> ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" <==\n", 1);
}

int		get_len(int fd)
{
	int		len;
	char	buff[1];

	len = 0;
	while ((read(fd, buff, 1)) > 0)
		len++;
	close(fd);
	return (len);
}

int		read_stdin(t_data *data)
{
	char			buff[900000];
	int				rd;
	unsigned int	i;

	i = 0;
	while ((rd = (read(0, buff, 900000))) > 0)
		;
	if (rd < 0)
		return (put_error2(5, basename(data->av[0])));
	while (buff[i])
	{
		if (ft_strlen(buff + i) <= (unsigned int)data->offset)
			write(1, buff + i, 1);
		i++;
	}
	return (0);
}

int		read_file(t_data *data, int first)
{
	int				fd;
	unsigned int	len;
	char			buff[1];

	if ((fd = open(data->av[data->arg_i], O_RDONLY)) < 1)
		return (put_error(1, data->av[data->arg_i], basename(data->av[0])));
	if (data->name)
		display_name(data->av[data->arg_i], first);
	len = 0;
	if (fd > 2)
		len = get_len(fd);
	fd = open(data->av[data->arg_i], O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		if (len <= (unsigned int)data->offset)
			write(1, buff, 1);
		len--;
	}
	close(fd);
	return (0);
}
