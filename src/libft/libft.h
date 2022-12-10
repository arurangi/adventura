/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:27:17 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/10 15:17:40 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

int			ft_printf(const char *str, ...);

int			ft_strlen(const char *s);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void		ft_putnbr(int nbr);
int			ft_putnbr_mod(int nbr, int *counter);
int			ft_putnbr_u(unsigned int nbr, int *counter);
int			ft_puthex(unsigned long nbr, char format, int *counter);
int			ft_isalpha(int c);
void		ft_putfs(char ch, va_list args, int *counter);

char		*ft_strjoin_mod(char *old_stash, char *buff);
char		*ft_strdup(const char *str);
int			ft_strchr_mod(const char *s, char ch);

char		*ft_itoa(int nbr);
char		**ft_split(char const *str, char ch);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split_fd(char *filepath, char seperator);

char		*get_next_line(int fd);
char		*save_raw_line(int fd, char *stash);
char		*trim_right(char *raw_line);
char		*trim_left(char *stash);
char		*free_stash(char *stash);

#endif