/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:21:11 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/23 18:37:45 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(unsigned long size)
{
	void			*res;
	unsigned char	*tmp;

	if (!(res = malloc(size)))
		return (NULL);
	tmp = (unsigned char *)res;
	while (size--)
		*tmp++ = 0;
	return (res);
}
