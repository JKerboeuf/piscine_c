/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:27 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/24 16:15:37 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

# define BUFF_SIZE 4096

typedef struct	s_data
{
	char		**map;
	char		rules[3];
	int			sq_size;
	int			sq_i;
	int			sq_j;
	int			line;
	int			col;
}				t_data;

void			hunt(t_data *data);
int				min_square(t_data *data);
void			insert_result(t_data *data);

void			print_bsq(t_data *data);
void			*put_error_ptr(char *to_free);
int				put_error_int(void);

int				check_first_line(char *line, t_data *data);
int				check_file(char *file, t_data *data);

void			*free_data(t_data *data);
int				free_split(char **split);

t_data			*init_data(char *file);
int				build_data(char *file, t_data *data);

char			*read_stdin(void);
long long		get_size(char *name);
char			*read_file(char *name);

#endif
