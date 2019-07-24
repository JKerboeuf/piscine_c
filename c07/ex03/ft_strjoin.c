/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:20:05 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 12:28:12 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*res;
	unsigned int	i;

	res = dest;
	i = 0;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (res);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*init(int size, char **strs, char *sep, int *mem)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (!strs | !sep)
		return (NULL);
	if (size <= 0)
	{
		res = (char*)malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	while (i < size && strs[i])
	{
		j = 0;
		while (strs[i][j])
			j++;
		*mem = *mem + j;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (*mem + ft_strlen(sep) * (size)));
	res[0] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		mem;

	i = 0;
	mem = 0;
	res = init(size, strs, sep, &mem);
	if (!res)
		return (NULL);
	if (size <= 0)
		return (res);
	while (i < size && strs[i])
	{
		res = ft_strncat(res, strs[i], ft_strlen(strs[i]));
		if (i < size - 1)
			res = ft_strncat(res, sep, ft_strlen(sep));
		i++;
	}
	res[mem + ft_strlen(sep) * (size - 1)] = '\0';
	return (res);
}
