/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/06 19:34:41 by Arsene           ###   ########.fr       */
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

/* PARSING */
# define BUFFER_SIZE 1

/* WINDOW SIZE */
# define W_WIDTH 800
# define W_HEIGHT 640

# define HUD 40

// HOOK MACROS
# define KEYPRESS 2
# define KEYPRESS_MASK 1L<<0
# define LEAVE_WINDOW_MASK (1L<<5)
# define DESTROY_NOTIFY	17

/* TILESET SIZE */
# define TILE 40

/* VELOCITY */
# define VELOCITY 1

/* INPUT KEYS (HOME SETUP) */
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363


/* INPUT KEYS (SCHOOL SETUP) */
// # define ESC 53
// # define UP 13
// # define DOWN 1
// # define LEFT 0
// # define RIGHT 2

typedef enum e_sprite {
	__player = 0,
	__board = 1,
	__emptyspace = 2,
	__wall = 3,
	__collectible = 4,
	__exit = 5,
	__enemy = 6,
} t_sprite;

/*         STRUCTURES         */
typedef struct s_node{
	int		row;
	int		col;
} t_node;

typedef struct s_asset
{
	void	*img;
	int		width;
	int		height;
	char	*addr; // addr
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	char	*filepath;
}	t_asset;

typedef struct s_game {
	void		*mlx;
	void		*window;
	char		**map; // Free
	char		*map_filepath;
	int			map_height;
	int			map_width;
	int			c_credit;
	int			e_credit;
	int			p_credit;
	t_node		starting_pos;
	t_asset		sprites[16];
	//t_asset		empty_space;
	int			x_shift;
	int			y_shift;
	int			angle;
	int			movements;
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

char		*ft_itoa(int nbr);
char		**ft_split(char const *str, char ch);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split_fd(char *filepath, char seperator);

char		*get_next_line(int fd);
char		*save_raw_line(int fd, char *stash);
char		*trim_right(char *raw_line);
char		*trim_left(char *stash);
char		*free_stash(char *stash);


/* START GAME*/
void		start_game(t_game *game);
int			game_init(t_game *game, char **av);
void		map_init(t_game *game); 

/* END GAME */
int			game_over(t_game *game);
void		free_matrix(char **matrix);
void		free_assets(t_game *game);

/* MAP RELATED */
int			map_checker(t_game *game);
int			valid_character(char ch); // Check map for valid characters
int			invalid_extension(char *filepath);
int			path_finder(t_game *game);
int			tab_height(char **tab);
int			in_queue(t_node current, t_node *queue, int head, int tail);
void		q_init(t_node *queue, int q_size);
int			found_exit(t_game *game, t_node node);
t_node		add_node(int row, int col);
void		add_neighbours(t_game *game, t_node *queue, int head, int *tail);

/* INPUT */
int			handle_input(int keysym, t_game *game);
int			is_walkable(char ch);
void		move(t_game *game, int keysym);

/* ERROR HANDLING */
int			error_msg(int return_code, char *message, ...);
int			success_msg(int return_code, char *message, ...);

/* RENDERING */
void		load_assets(t_game *game);
void		save_assets(t_game *game, char **path);
void		free_assets(t_game *game);
int			render(t_game *game);
void		render_sprite(t_game *game, char asset, int x, int y);
int			rgbify(uint8_t red, uint8_t green, uint8_t blue);
void		render_HUD(t_game *game);

#endif