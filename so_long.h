/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:48 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/21 16:20:01 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include "src/libft/libft.h"
# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "mlx/mlx.h"
# include <stdio.h>

/* GAME MACROS */
# define TILE 40
# define HUD 80
# define SPRITES_NBR 31
# define VELOCITY 1
# define BUFFER_SIZE 1

/* INPUT KEYS (HOME SETUP) */
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

/* INPUT KEYS (SCHOOL SETUP #1) */
// # define ESC 53
// # define UP 13
// # define DOWN 1
// # define LEFT 0
// # define RIGHT 2

/* ENUMS */
typedef enum e_events {
	keypress = 2,
	destroy_notify = 17,
	keypress_mask = 1L<<0,
	leave_window_mask = 1L<<5,
}	t_events;

typedef enum e_sprite {
	_emptyspace = 0,
	_wall_inside = 1,
	_wall_top_left = 2,
	_wall_top_right = 3,
	_wall_bottom_left = 4,
	_wall_bottom_right = 5,
	_wall_top1 = 6,
	_wall_top2 = 7,
	_wall_middle_left1 = 8,
	_wall_middle_left2 = 9,
	_wall_middle_right1 = 10,
	_wall_middle_right2 = 11,
	_coins = 12,
	_treasure_chest = 13,
	_exit_closed = 14,
	_exit_opened = 15,
	_player_down = 16,
	_player_up = 17,
	_player_left = 18,
	_player_right = 19,
	_enemy1 = 20,
	_enemy2 = 21,
	_enemy3 = 22,
	_enemy4 = 23,
}	t_sprite;

/* STRUCTURES */
typedef struct s_node{
	int		row;
	int		col;
}	t_node;

typedef struct s_asset
{
	char			*path;
	void			*img;
	int				width;
	int				height;
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
	int			plr_angle;
	int			movements;
	int			state;
	int			life_points;
	int			delay;
	int			polarity;
}	t_game;

/* START/END */
int			game_init(t_game *game, char **av);
void		start_game(t_game *game);
int			end_game(t_game *game);

/* INITIALIZATION */
void		map_init(t_game *game, char **av);
void		player_init(t_game *game);

/* MAP RELATED */
int			map_checker(t_game *game);
int			valid_character(char ch);
int			invalid_extension(char *filepath);
int			inner_loop_checker(t_game *game, int row, int col);
int			outer_loop_checker(t_game *game);

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
void		move(t_game *game, int keysym, int x, int y);
int			is_walkable(t_game *game, char ch);
int			is_walkable_enemy(char ch);

/* RENDERING */
int			load_assets(t_game *game);
void		load_heart(t_game *game);
int			save_assets(t_game *game);

int			render(t_game *game);
void		render_sprite(t_game *game, int asset, int col, int row);
void		render_hud(t_game *game);

void		animate(t_game *game, int x, int y);
void		add_delay(t_game *game, int frame);

void		identify_sprites(t_game *game, int row, int col);
void		identify_walls(t_game *game, int x, int y);
void		identify_exit(t_game *game, int x, int y);
void		top_walls(t_game *game, int x, int y);
void		bottom_walls(t_game *game, int x, int y);
void		inner_walls(t_game *game, int x, int y);

int			rgbify(uint8_t red, uint8_t green, uint8_t blue);

/* Memory management */
int			free_arr_nodes(int return_code, t_node *queue);
void		free_matrix(char **matrix);
void		free_hud(char **hud_data);

/* ERROR HANDLING */
int			error_msg(int return_code, char *message, ...);
int			success_msg(int return_code, char *message, ...);

void		update_life_points(t_game *game);
void		render_and_update(t_game *game);
void		process_input(t_game *game);

#endif
