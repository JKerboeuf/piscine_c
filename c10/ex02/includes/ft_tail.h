/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:45:31 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/18 13:09:11 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include "libft.h"
# include <fcntl.h>
# include <libgen.h>

typedef struct	s_data
{
	int		ac;
	char	**av;
	int		arg_i;
	int		offset;
	int		name;
}				t_data;

void			ft_putstr_fd(char *str, int fd);

t_data			*init_data(int ac, char **av);

int				check_option(t_data *data);
int				check_option2(char **av);
int				check_option3(char **av);
int				put_error(int code, char *str, char *name);
int				put_error2(int code, char *name);

int				read_file(t_data *data, int first);
int				read_stdin(t_data *data);
void			display_name(char *name, int first);
int				get_len(int fd);

#endif
