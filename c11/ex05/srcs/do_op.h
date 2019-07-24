/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:34:40 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/15 17:40:18 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif
