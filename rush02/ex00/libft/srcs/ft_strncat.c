/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:54:09 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/20 13:29:39 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *res;

	res = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}
