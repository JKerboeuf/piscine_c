/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:26:48 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/18 15:00:43 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		put_error(int code, char *str, char *name)
{
	if (code == 1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (code == 2)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": illegal option -- ", 2);
		write(2, &str[0], 1);
		ft_putstr_fd("\nusage: tail [-c #] [file ...]\n", 2);
	}
	else if (code == 3)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": illegal offset -- ", 2);
		ft_putstr_fd(str, 2);
		write(2, "\n", 1);
	}
	return (1);
}

int		put_error2(int code, char *name)
{
	if (code == 4)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": option requires an argument -- c\n", 2);
		ft_putstr_fd("usage: tail [-c #] [file ...]\n", 2);
	}
	else if (code == 5)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": stdin: Is a directory\n", 2);
	}
	return (1);
}

int		check_option3(char **av)
{
	put_error(2, av[1] + 1, basename(av[0]));
	return (-1);
}

int		check_option2(char **av)
{
	if (av[1][2])
		put_error(3, av[1] + 2, basename(av[0]));
	else
		put_error(3, av[2], basename(av[0]));
	return (-1);
}

int		check_option(t_data *data)
{
	if (!data->av[1])
		return (1);
	if (ft_strstr(data->av[1], "-c"))
	{
		if (!data->av[1][2] && !data->av[2])
		{
			put_error2(4, basename(data->av[0]));
			return (-1);
		}
		else if (!data->av[1][2] && data->av[2] && ft_str_is_num(data->av[2]))
		{
			data->offset = ft_atoi(data->av[2]);
			return (3);
		}
		else if (data->av[1][2] && ft_str_is_num(data->av[1] + 2))
		{
			data->offset = ft_atoi(data->av[1] + 2);
			return (2);
		}
		else
			return (check_option2(data->av));
	}
	else if (data->av[1][0] == '-' && data->av[1][1] != 'c')
		return (check_option3(data->av));
	return (1);
}
