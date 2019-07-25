/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:10:15 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/25 11:39:34 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char			*read_stdin(void)
{
	unsigned long	size;
	int				rd;
	char			buff[BUFF_SIZE];
	char			*res;

	size = BUFF_SIZE;
	if (!(res = (char*)malloc(sizeof(char) * size)))
		return (put_error_ptr(NULL));
	while ((rd = (read(0, buff, BUFF_SIZE))) > 0)
	{
		res = ft_strncat(res, buff, rd);
		if (rd > 0)
			if (!(res = (char*)ft_realloc(res, size, size + BUFF_SIZE)))
				return (put_error_ptr(NULL));
		size += BUFF_SIZE;
	}
	if (rd < 0)
		return (put_error_ptr(res));
	return (res);
}

long long		get_size(char *name)
{
	int				fd;
	long long		len;
	int				rd;
	char			buff[BUFF_SIZE];

	len = 0;
	if ((fd = open(name, O_RDONLY)) < 3)
	{
		put_error_ptr(NULL);
		return (-1);
	}
	if (ft_strstr(name, "/dev/"))
	{
		put_error_ptr(NULL);
		return (-1);
	}
	while ((rd = (read(fd, buff, BUFF_SIZE))) > 0)
		len += rd;
	close(fd);
	return (len);
}

char			*read_file(char *name)
{
	long long		size;
	int				fd;
	int				rd;
	char			*res;

	size = get_size(name);
	if (size < 0)
		return (NULL);
	if (size == 0)
		return (put_error_ptr(NULL));
	if ((fd = open(name, O_RDONLY)) < 3)
		return (put_error_ptr(NULL));
	if (!(res = (char*)malloc(sizeof(char) * (size))))
		return (put_error_ptr(NULL));
	res[size] = '\0';
	rd = (read(fd, res, size));
	if (rd < 0)
		return (put_error_ptr(res));
	close(fd);
	return (res);
}
