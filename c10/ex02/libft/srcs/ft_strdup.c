/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:54:55 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/16 10:22:20 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * ft_strlen(src))))
		return (0);
	ft_strcpy(res, src);
	return (res);
}
