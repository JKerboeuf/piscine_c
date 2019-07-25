/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:37:24 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/22 17:53:14 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned char *buff1;
	unsigned char *buff2;

	buff1 = (unsigned char *)((unsigned long)dst);
	buff2 = (unsigned char *)((unsigned long)src);
	while (n--)
		*buff1++ = *buff2++;
	return (dst);
}

void		*ft_realloc(void *ptr, unsigned long old, unsigned long size)
{
	void *new;

	if (!(new = ft_memalloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, old);
	free(ptr);
	return (new);
}
