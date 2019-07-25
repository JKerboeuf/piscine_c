/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:41:08 by jukerboe          #+#    #+#             */
/*   Updated: 2019/07/23 20:08:03 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int					ft_atoi(char *str);
unsigned long long	ft_atol(char *str);
void				*ft_memalloc(unsigned long size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *str);
void				ft_putstrnl(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_putstrnl_fd(char *str, int fd);
void				ft_putnbr(int nb);
void				ft_putnbrnl(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbrnl_fd(int nb, int fd);
void				*ft_realloc(void *p, unsigned long old, unsigned long n);
char				**ft_split(char *str, char *charset);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_strcat(char *dest, char *src);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
char				*ft_strjoin(int size, char **strs, char *sep);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int		ft_strlen(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strupcase(char *str);

#endif
