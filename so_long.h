/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/02 16:02:46 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // printf
# include <mlx.h> // Acccess the minilibx functions
# include <fcntl.h> // 
# include <stdio.h> // FOPEN_MAX

// Macros
# define BUFFER_SIZE 1

# define W_WIDTH 800
# define W_HEIGHT 640

// # define ESC 65307
// # define UP 65362
// # define DOWN 65364
// # define LEFT 65361
// # define RIGHT 65363

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define TILE 40

/*         STRUCTURES         */
typedef struct s_node{
	int		row;
	int		col;
} t_node;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*addr; // addr
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_asset {
	void	*ptr;
	int		width;
	int		height;
} t_asset;

typedef struct s_game {
	void	*mlx;
	void	*window;
	char	**map; // Free
	char	*map_filepath;
	int		map_height;
	int		map_width;
	int		c_credit;
	int		e_credit;
	int		p_credit;
	t_node	starting_pos;
	t_img	image;
	t_asset	empty_space;
	int		x_shift;
	int		y_shift;
	// t_img	player;
	// t_img	collectible;
	// t_img	exit;
	// t_img	wall;
}	t_game;

typedef struct s_shape {
	int x;
	int y;
	int width;
	int height;
	int color;
} t_shape;

/* *********************** */
/*     BASIC & PRINT_F     */
/* *********************** */

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

char		**ft_split(char const *str, char ch);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split_fd(char *filepath, char seperator);

/*  GET_NEXT_LINE  */

char		*get_next_line(int fd);
char		*save_raw_line(int fd, char *stash);
char		*trim_right(char *raw_line);
char		*trim_left(char *stash);
char		*free_stash(char *stash);

int			map_checker(t_game *game);
int			not_valid_character(char ch); // Check map for valid characters
void		map_init(t_game *game); // Initialize credits for C, E and P

/*     CHECK VALID MAP     */
int			invalid_extension(char *filepath);
int			path_finder(t_game *game);
int			tab_height(char **tab);

/*     ERROR HANDLING        */
int			map_error(char *message, ...);
int			game_error(char *message, ...);
void		free_matrix(char **matrix);
int			success_msg(int code, char *message, ...);

/*      INPUT             */
int			handle_input(int keysym, t_game *game);

/*     PATH FINDER        */
int			in_queue(t_node current, t_node *queue, int head, int tail);
void		q_init(t_node *queue, int q_size);
int			found_exit(t_game *game, t_node node);
t_node		add_node(int row, int col);
void		add_neighbours(t_game *game, t_node *queue, int head, int *tail);

/*     RENDERING          */
int			render(t_game *game);
void		img_pix_put(t_img *img, int x, int y, int color);
int			encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void		render_background(t_img *img, int color);
int			render_rect(t_img *img, t_shape rect);

/*       INITIALIZER       */
int			init_game_environment(t_game *game, int ac, char **av);

#endif