/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 12:02:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <mlx.h> // Acccess the minilibx functions
# include <fcntl.h>

// Gobal informations
typedef struct s_game {
	void	*mlx;
	void	*window;
	char	**map;
	char	*mpath;
	char	*path;
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*exit;
}	t_game;


int			ft_printf(const char *str, ...);
size_t		ft_strlen(const char *s);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nbr, int *counter);
int			ft_putnbr_u(unsigned int nbr, int *counter);
int			ft_puthex(unsigned long nbr, char format, int *counter);
int			ft_isalpha(int c);
void		ft_putfs(char ch, va_list args, int *counter);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

void		draw_map(t_game *game);
int			map_is_valid(char *game);

#endif