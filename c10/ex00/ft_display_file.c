/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:02:47 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/16 15:48:28 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		put_error(int code)
{
	if (code == 1)
		write(2, "File name missing.\n", 19);
	else if (code == 2)
		write(2, "Too many arguments.\n", 20);
	else if (code == 3)
		write(2, "Cannot read file.\n", 18);
	return (code);
}

int		read_file(char *nom)
{
	int		fd;
	char	buff[1];
	int		rd;

	if ((fd = open(nom, O_RDONLY)) < 1)
		return (put_error(3));
	while ((rd = read(fd, buff, 1)) > 0)
		write(1, buff, 1);
	if (rd < 0)
		return (put_error(3));
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (put_error(1));
	else if (ac != 2)
		return (put_error(2));
	else
		return (read_file(av[1]));
	return (0);
}
