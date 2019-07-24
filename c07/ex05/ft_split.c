/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:07:45 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 12:02:58 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (!str || !charset)
		return (-1);
	while (str[i])
	{
		if (!is_sep(str[i], charset) && (is_sep(str[i + 1], charset)
			|| str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

char	*ft_strndup(char *str, char *charset, int i)
{
	int		j;
	int		tmp;
	char	*res;

	j = 0;
	tmp = i;
	while (str[i] && !is_sep(str[i], charset))
	{
		i++;
		j++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = 0;
	while (str[tmp] && !is_sep(str[tmp], charset))
	{
		res[j] = str[tmp];
		j++;
		tmp++;
	}
	res[j] = '\0';
	return (res);
}

char	**alloc(char *str, char *charset, int *i, int *j)
{
	int		size;
	char	**res;

	size = count_words(str, charset);
	if (!(res = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	if (!size || !count_words(str, charset))
	{
		res[0] = 0;
		return (res);
	}
	while (str[*i] && is_sep(str[*i], charset))
		*i = *i + 1;
	if (!is_sep(str[*i], charset))
	{
		res[*j] = ft_strndup(str, charset, *i);
		*j = *j + 1;
	}
	res[size] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !charset || !*str)
		return (NULL);
	if (!(res = alloc(str, charset, &i, &j)))
		return (NULL);
	while (str[i] && str[i + 1])
	{
		if (is_sep(str[i], charset) && !is_sep(str[i + 1], charset))
		{
			res[j] = ft_strndup(str, charset, i + 1);
			j++;
		}
		i++;
	}
	return (res);
}
