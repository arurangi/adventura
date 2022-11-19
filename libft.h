/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 14:19:23 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <mlx.h> // Acccess the minilibx functions

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr, int *counter);
int		ft_putnbr_u(unsigned int nbr, int *counter);
int		ft_puthex(unsigned long nbr, char format, int *counter);
int		ft_isalpha(int c);
void	ft_putfs(char ch, va_list args, int *counter);

#endif