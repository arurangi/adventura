/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/23 12:22:56 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // printf
# include <mlx.h> // Acccess the minilibx functions
# include <fcntl.h> // 
# include <stdio.h> // FOPEN_MAX
# define BUFFER_SIZE 1

// Macros


// Gobal informations
typedef struct s_game {
	void	*mlx;
	void	*window;
	char	**map;
	char	*mpath;
	int		map_height;
	int		map_width;
	int		c_credit;
	int		e_credit;
	int		p_credit;
	char	*path;
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*exit;
}	t_game;

/*  BASIC & PRINT_F  */
int			ft_printf(const char *str, ...);

int			ft_strlen(const char *s);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nbr, int *counter);
int			ft_putnbr_u(unsigned int nbr, int *counter);
int			ft_puthex(unsigned long nbr, char format, int *counter);
int			ft_isalpha(int c);
void		ft_putfs(char ch, va_list args, int *counter);

char	*ft_strjoin_mod(char *old_stash, char *buff);
char	*ft_strdup(const char *str);
int		ft_strchr_mod(const char *s, char ch);

/*  GET_NEXT_LINE  */

char	*get_next_line(int fd);
char	*save_raw_line(int fd, char *stash);
char	*trim_right(char *raw_line);
char	*trim_left(char *stash);
char	*free_stash(char *stash);

void		draw_map(t_game *game);
int			map_is_valid(t_game *game);
int			not_valid_character(char ch); // Check map for valid characters
void		map_init(t_game *game); // Initialize credits for C, E and P


#endif