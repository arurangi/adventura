/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/14 19:57:50 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../so_long.h"

int	render(t_game *game)
{
	int	row;
	int	col;


	// Clear previous images
	mlx_clear_window(game->mlx, game->window);

	// Render the heads-up display
	render_hud(game);

	// Render the map
	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			identify_sprites(game, row, col);
			col++;
		}
		row++;
	}

	// Render player
	render_sprite(game, game->plr_angle, game->x_shift, game->y_shift);

	// Slow the loss of life points (delay)
	if (game->map[game->y_shift][game->x_shift] == 'N')
	{
		if ((game->delay % 21 == 20) && game->life_points > 0)
			game->life_points -= 1;
		usleep(100);
	}
	return (0);
}

void	render_enemies(t_game *game, int row, int col)
{
	int	id;
	int	x;
	int	y;
	int	pos;

	id = find_which_enemy(game, row, col);
	if (id == -1)
	{
		error_msg(0, "no enemy matched");
		return ;
	}
	x = game->enemies[id].x;
	y = game->enemies[id].y;
	pos = game->enemies[id].frame_pos;

	// Render enemy with that ID
	mlx_put_image_to_window(game->mlx, game->window, game->enemies[id].frames[pos].img, x * TILE, y * TILE + HUD);

	// Update position, or polarity if 
	info_msg(1, "Enemy [%d] at (%d, %d)", id, y, x);
	if (is_walkable_enemy(game, y, x + (1 * game->enemies[id].polarity)))
	{
		if (game->delay % 31 == 30)
		{
			info_msg(1, "--- can move +1 step");
			game->enemies[id].x = x * (1 + game->enemies[id].polarity);
			// game->map[y][x] = '0';
			// game->map[y][x + (1 * game->polarity)] = 'N';
		}
	}
	else
		game->enemies[id].polarity *= -1;

	game->delay += 1;
	if (game->delay % 11 == 10)
		game->enemies[id].frame_pos += 1 % MAX_FRAMES;
	usleep(10);
}

int	find_which_enemy(t_game *game, int row, int col)
{
	int id;
	
	id = 0;
	while (id < game->n_credit)
	{
		if (row == game->enemies[id].y && col == game->enemies[id].x)
			return (id);
		id++;
	}
	return (-1);
}

void	identify_sprites(t_game *game, int row, int col)
{
	if (game->map[row][col] == '0' || game->map[row][col] == 'P')
		render_sprite(game, _emptyspace, col, row);
	else if (game->map[row][col] == '1')
		identify_walls(game, col, row);
	else if (game->map[row][col] == 'C')
		render_sprite(game, _coins, col, row);
	else if (game->map[row][col] == 'T')
		render_sprite(game, _treasure_chest, col, row);
	else if (game->map[row][col] == 'E')
		identify_exit(game, col, row);
	else if (game->map[row][col] == 'N')
		render_enemies(game, row, col);
	else
		return ;
}
