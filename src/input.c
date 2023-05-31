/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/30 20:23:56 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle user input {W, S, A, D} to have ability to
 * move in all directions within the walls
*/

#include "so_long.h"

void	process_input(t_game *game)
{
	mlx_hook(game->window, keypress, keypress_mask, &handle_input, game);
	mlx_hook(game->window, destroy_notify, leave_window_mask, &end_game, game);
}

int	handle_input(int keysym, t_game *game)
{
	int	*x;
	int	*y;

	x = &game->x_shift;
	y = &game->y_shift;
	if (!game)
		return (error_msg(0, "game struct missing, can't handle input"));
	if (is_arrow_keys(keysym))
		move(game, keysym, game->x_shift, game->y_shift);
	if (keysym == ESC_KEY || game->life_points == 0
		|| (game->map[*y][*x] == 'E' && game->c_credit == 0))
		end_game(game);
	if (game->map[*y][*x] == 'C' || game->map[*y][*x] == 'T')
	{
		if (game->map[*y][*x] == 'C')
			game->c_credit -= 1;
		game->map[*y][*x] = '0';
	}
	return (0);
}

void	move(t_game *game, int keysym, int x, int y)
{
	// float delta_time = 

	// // wait some time until we reach the target frame time
	// int currentTicks;
    // do {
    //     currentTicks = mlx_get_time();
    // } while ((currentTicks - ticksLastFrame) < FRAME_TIME_LENGTH);

	// // difference in ticks from last frame converted to seconds
    // float deltaTime = (currentTicks - ticksLastFrame) / 1000.0f;
    // ticksLastFrame = currentTicks;


	game->player_moved = TRUE;
	switch (keysym)
	{
		case LEFT_KEY: {
			game->plr_angle = WEST;
			if (is_walkable(game, game->map[y][x - PLAYER_JUMP])) {
				render_sprite(game, _emptyspace, x, y);
				game->x_shift -= PLAYER_JUMP;
			}
			break ;
		}
		case RIGHT_KEY: {
			game->plr_angle = EAST;
			if (is_walkable(game, game->map[y][x + PLAYER_JUMP])) {
				render_sprite(game, _emptyspace, x, y);
				game->x_shift += PLAYER_JUMP;
			}
			break ;
		}
		case DOWN_KEY: {
			game->plr_angle = SOUTH;
			if (is_walkable(game, game->map[y + PLAYER_JUMP][x])) {
				render_sprite(game, _emptyspace, x, y);
				game->y_shift += PLAYER_JUMP;
			}
			break ;
		}
		case UP_KEY: {
			game->plr_angle = NORTH;
			if (is_walkable(game, game->map[y - PLAYER_JUMP][x])) {
				render_sprite(game, _emptyspace, x, y);
				game->y_shift -= PLAYER_JUMP;
			}
			break ;
		}
	}
}

int	end_game(t_game *game)
{
	if (game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		draw_black_screen(game);
		usleep(500000);
		mlx_destroy_window(game->mlx, game->window);
	}
	if (game->map != NULL)
		free_matrix(game->map);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
