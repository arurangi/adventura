/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/12 11:03:02 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBRARIES */
# include "src/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>

/* GAME MACROS */
# define TILE 40
# define HUD 40
# define SPRITES_NBR 6
# define VELOCITY 1
# define BUFFER_SIZE 1

/* INPUT KEYS (HOME) */
// # define ESC 65307
// # define UP 65362
// # define DOWN 65364
// # define LEFT 65361
// # define RIGHT 65363

/* INPUT KEYS (SCHOOL) */
# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

/* ENUMS */
typedef enum e_events {
	keypress = 2,
	destroy_notify = 17,
	keypress_mask = 1L<<0,
	leave_window_mask = 1L<<5,
}	t_events;

typedef enum e_sprite {
	_emptyspace = 0,
	_wall = 1,
	_collectible = 2,
	_exit_closed = 4,
	_exit_opened = 5,
	_player = 6,
}	t_sprite;

/* STRUCTURES */
typedef struct s_node{
	int		row;
	int		col;
}	t_node;

typedef struct s_asset
{
	char	*path;
	void	*img;
	int		width;
	int		height;
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
	t_asset		sprites[SPRITES_NBR];
	int			x_shift;
	int			y_shift;
	int			movements;
}	t_game;

/* START/END */
int			game_init(t_game *game, char **av);
void		start_game(t_game *game);
int			end_game(t_game *game);

/* INITIALIZATIONS */
void		map_init(t_game *game, char **av);
void		player_init(t_game *game);

/* MAP RELATED */
int			map_checker(t_game *game);
int			valid_character(char ch); // Check map for valid characters
int			invalid_extension(char *filepath);
int			inner_loop_checker(t_game *game, int row, int col);
int			outer_loop_checker(t_game *game, int row, int col);

int			path_finder(t_game *game);
void		q_init(t_node *queue, int q_size);
t_node		add_node(int row, int col);
void		add_neighbours(t_game *game, t_node *queue, int head, int *tail);
int			found_exit(t_game *game, t_node node);
int			in_queue(t_node current, t_node *queue, int head, int tail);
int			valid_position(t_game *game, int row, int col, t_node current);
int			tab_height(char **tab);

/* INPUT */
int			handle_input(int keysym, t_game *game);
void		move(t_game *game, int keysym);
int			is_walkable(t_game *game, char ch);

/* RENDERING */
int			load_assets(t_game *game);
int			save_assets(t_game *game);

int			render(t_game *game);
void		render_sprite(t_game *game, int asset, int x, int y);
void		render_player(t_game *game, int x, int y);
void		render_hud(t_game *game);

int			rgbify(uint8_t red, uint8_t green, uint8_t blue);

/* Memory management */
int			free_arr_nodes(int return_code, t_node *queue);
void		free_matrix(char **matrix);

/* ERROR HANDLING */
int			error_msg(int return_code, char *message, ...);
int			success_msg(int return_code, char *message, ...);

#endif