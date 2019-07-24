/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 08:42:48 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/14 19:05:07 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);

int		put_error(char *str);
int		check_error(int ac, char **av);
int		get_len(char *av);
int		*init_lim(char *av);
int		*init_map(int size);

int		ft_fill(int *tab, int *cote, int pos);
int		isposable(int *tab, int pos, int i);

int		check_left(int *tab, int num, int pos);
int		check_right(int *tab, int num, int pos);
int		check_down(int *tab, int num, int pos);
int		check_up(int *tab, int num, int pos);
int		check_valid(int *tab, int *cote);

#endif
