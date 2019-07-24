/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:35:39 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 16:09:19 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		put_error_arg(int code)
{
	ft_putstrnl_fd("Error", 2);
	if (code == 1)
		ft_putstrnl_fd("Too few arguments.", 2);
	else if (code == 2)
		ft_putstrnl_fd("Too many arguments.", 2);
	else if (code == 3)
		ft_putstrnl_fd("Number is not numeric.", 2);
	else if (code == 4)
		ft_putstrnl_fd("Number is too big.", 2);
	else if (code == 5)
		ft_putstrnl_fd("Number is negative.", 2);
	return (code);
}

int		put_error_dict(int code, char *name)
{
	ft_putstrnl_fd("Dict error", 2);
	if (code == 1)
		ft_putstrnl_fd("Default dict file \"dict/numbers.dict\" not found.", 2);
	else if (code == 2)
	{
		ft_putstr_fd("Dict file \"", 2);
		ft_putstr_fd(name, 2);
		ft_putstrnl_fd("\" not found.", 2);
	}
	else if (code == 3)
	{
		ft_putstr_fd("Dict file \"", 2);
		ft_putstr_fd(name, 2);
		ft_putstrnl_fd("\" is a directory.", 2);
	}
	else if (code == 4)
		ft_putstrnl_fd("Dict file is too big.", 2);
	else if (code == 5)
		ft_putstrnl_fd("One or more lines from base dict is missing.", 2);
	return (code);
}

int		put_error_split(int code, int line)
{
	ft_putstrnl_fd("Dict error", 2);
	if (code == -1)
	{
		ft_putstr_fd("Line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstrnl_fd(" is invalid.", 2);
	}
	else if (code == 2)
	{
		ft_putstr_fd("Number ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstrnl_fd(" was found twice.", 2);
	}
	else if (code == 3)
	{
		ft_putnbr_fd(line, 2);
		ft_putstrnl_fd(" line(s) from base dict is missing.", 2);
	}
	return (code);
}

int		check_minus(char *av)
{
	if (av[0] == '-')
		return (1);
	return (0);
}

int		check_args(int ac, char **av)
{
	if (ac < 2)
		return (put_error_arg(1));
	if (ac > 3)
		return (put_error_arg(2));
	if (check_minus(av[1]))
		return (put_error_arg(5));
	if (!ft_str_is_numeric(av[1]))
		return (put_error_arg(3));
	if (ft_strlen(av[1]) > 19)
		return (put_error_arg(4));
	return (0);
}
