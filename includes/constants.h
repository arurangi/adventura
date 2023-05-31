/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:31:06 by lupin             #+#    #+#             */
/*   Updated: 2023/05/30 19:52:38 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* GAME MACROS */
# define TRUE 1
# define FALSE 0

# define TILE_SIZE 40
# define HUD_HEIGHT 80
# define SPRITES_NBR 32
# define VELOCITY 1
# define PLAYER_JUMP 1
# define BUFFER_SIZE 1

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define HUD_STR1_Y (HUD_HEIGHT - 35) // life points
# define HUD_STR1_X (TILE_SIZE * 2 + 5)
# define HUD_STR2_Y (HUD_HEIGHT - 35) // steps
# define HUD_STR2_X  (TILE_SIZE * 3 + 40)


# define STATE_PERIOD 1
# define FIRST_FRAME_INDEX 20
# define NBR_OF_FRAMES 4

# define NORTH 17
# define SOUTH 16
# define WEST 18
# define EAST 19

/* INPUT KEYS (HOME SETUP) */
# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

/* INPUT KEYS (SCHOOL SETUP #1) */
// # define ESC_KEY 53
// # define UP_KEY 13
// # define DOWN_KEY 1
// # define LEFT_KEY 0
// # define RIGHT_KEY 2

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
	_game_over = 31
}	t_sprite;

#endif