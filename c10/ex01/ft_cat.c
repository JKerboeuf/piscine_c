/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:44:51 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/18 12:54:04 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <libgen.h>

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int		put_error(int code, char *file, char *name)
{
	if (code == 1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (code == 2)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	return (1);
}

int		read_file(char *av, char *name)
{
	int		fd;
	char	buff[16384];
	int		rd;

	if ((fd = open(av, O_RDONLY)) < 1)
	{
		put_error(1, av, name);
		return (1);
	}
	if (fd > 2)
	{
		while ((rd = read(fd, buff, 16384)) > 0)
			write(1, buff, rd);
		if (rd < 0)
		{
			put_error(2, av, name);
			return (1);
		}
		close(fd);
	}
	return (0);
}

void	read_stdin(char *name)
{
	char	buff[16384];
	int		rd;

	while ((rd = (read(0, buff, 16384))) > 0)
		write(1, buff, rd);
	if (rd < 0)
		put_error(2, "stdin", name);
}

int		main(int ac, char **av)
{
	int i;
	int err;

	i = 1;
	err = 0;
	if (ac == 1)
		read_stdin(basename(av[0]));
	while (i < ac && av[i])
	{
		if (read_file(av[i], basename(av[0])))
			err = 1;
		i++;
	}
	return (err);
}
