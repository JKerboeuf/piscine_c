/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:41:15 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/21 16:58:17 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_02_H
# define FT_RUSH_02_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define ULL unsigned long long

typedef struct	s_dict
{
	ULL			number;
	char		*literal;
}				t_dict;

int				put_error_arg(int code);
int				put_error_dict(int code, char *name);
int				put_error_split(int code, int line);
int				check_args(int ac, char **av);

int				read_dict(int fd, char *name, char *buff);
int				open_dict(int ac, char **av);
t_dict			*build_dict(char *buff);
t_dict			*init_dict(int ac, char **av);

int				free_split(char **split);
int				check_split(char **split);
int				check_line(char *line);

int				verif_dict(t_dict *dict);
int				free_dict(t_dict *dict);
void			sort_dict(t_dict *dict);
void			swap_dict(ULL *nb_a, ULL *nb_b, char **lit_a, char **lit_b);

void			put_translate(ULL nbr, t_dict *tab);
int				dict_size(t_dict *tab);

char			*strdup_space(char *str);

#endif
