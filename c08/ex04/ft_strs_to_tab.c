/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:54:41 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/13 09:20:24 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_strdup(char *src)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	ft_strcpy(res, src);
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;

	i = 0;
	if (!(res = malloc(sizeof(*res) * (ac + 1))))
		return (NULL);
	while (i <= ac)
	{
		(res + i)->size = (i != ac) ? ft_strlen(av[i]) : 0;
		(res + i)->str = (i != ac) ? av[i] : 0;
		(res + i)->copy = (i != ac) ? ft_strdup(av[i]) : 0;
		i++;
	}
	return (res);
}
