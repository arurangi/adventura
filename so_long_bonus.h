/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 16:58:09 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// Libraries
# include "src/libft/libft.h"
# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>

/* PARSING */
# define BUFFER_SIZE 1

/* WINDOW SIZE */
# define W_WIDTH 800
# define W_HEIGHT 640

# define HUD 40

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

typedef enum e_events {
	keypress = 2,
	destroy_notify = 17,
	keypress_mask = 1L<<0,
	leave_window_mask = 1L<<5,
}	t_events;

typedef enum e_sprite {
	__player = 0,
	__board = 1,
	__emptyspace = 2,
	__wall = 3,
	__collectible = 4,
	__exit = 5,
	__enemy = 6,
}	t_sprite;

/*         STRUCTURES         */
typedef struct s_node{
	int		row;
	int		col;
}	t_node;

typedef struct s_asset
{
	void	*img;
	int		width;
	int		height;
	char	*filepath;
}	t_asset;

typedef struct s_game {
	void		*mlx;
	void		*window;
	char		**map;
	char		*map_filepath;
	int			map_height;
	int			map_width;
	int			c_credit;
	int			e_credit;
	int			p_credit;
	t_node		starting_pos;
	t_asset		sprites[16];
	int			x_shift;
	int			y_shift;
	int			angle;
	int			movements;
}	t_game;

typedef struct s_shape {
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_shape;

/* START GAME*/
void		start_game(t_game *game);
int			game_init(t_game *game, char **av);
void		map_init(t_game *game);

/* END GAME */
int			game_over(t_game *game);
void		free_matrix(char **matrix);

/* MAP RELATED */
int			map_checker(t_game *game);
int			valid_character(char ch); // Check map for valid characters
int			invalid_extension(char *filepath);
int			inner_loop_checker(t_game *game, int row, int col);
int			after_loop_checker(t_game *game, int row, int col);
int			path_finder(t_game *game);
int			tab_height(char **tab);
int			in_queue(t_node current, t_node *queue, int head, int tail);
void		q_init(t_node *queue, int q_size);
int			found_exit(t_game *game, t_node node);
t_node		add_node(int row, int col);
void		add_neighbours(t_game *game, t_node *queue, int head, int *tail);
int			valid_position(t_game *game, int row, int col, t_node current);

/* INPUT */
int			handle_input(int keysym, t_game *game);
int			is_walkable(t_game *game, char ch);
void		move(t_game *game, int keysym);

/* Memory management */
int			free_array(int return_code, t_node *queue);

/* ERROR HANDLING */
int			error_msg(int return_code, char *message, ...);
int			success_msg(int return_code, char *message, ...);

/* RENDERING */
int			load_assets(t_game *game);
int			save_assets(t_game *game, char **path);
void		free_assets(t_game *game);
int			render(t_game *game);
void		render_sprite(t_game *game, char asset, int x, int y);
void		render_player(t_game *game, int x, int y);
int			rgbify(uint8_t red, uint8_t green, uint8_t blue);
void		render_hud(t_game *game);

#endif