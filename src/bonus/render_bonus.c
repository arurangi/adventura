/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/08 15:05:26 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../../so_long_bonus.h"

int	render(t_game *game)
{
	int	y;
	int	x;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				render_sprite(game, _emptyspace, x, y);
			else if (game->map[y][x] == '1')
				identify_walls(game, x, y);
			else if (game->map[y][x] == 'C')
				render_sprite(game, _coins, x, y);
			else if (game->map[y][x] == 'T')
				render_sprite(game, _treasure_chest, x, y);
			else if (game->map[y][x] == 'E')
				identify_exit(game, x, y);
			else if (game->map[y][x] == 'N')
				animate(game, x, y);
			x++;
		}
		y++;
	}
	render_sprite(game, game->angle, game->x_shift, game->y_shift);
	render_hud(game);
	return (0);
}

void	animate(t_game *game, int x, int y)
{
	int	frame;

	frame = game->state;
	render_sprite(game, frame + 20, x, y);
	game->state = (frame + 1) % 4;
	usleep(100000);
}

void	identify_exit(t_game *game, int x, int y)
{
	if (game->c_credit == 0)
		render_sprite(game, _exit_opened, x, y);
	else
		render_sprite(game, _exit_closed, x, y);
}

void	identify_walls(t_game *game, int x, int y)
{
	// top
	if (y == 0)
	{
		if (x == 0)
			render_sprite(game, _wall_top_left, x, y);
		else if (x == game->map_width - 1)
			render_sprite(game, _wall_top_right, x, y);
		else
			render_sprite(game, _wall_top1, x, y);
	}
	// bottom
	else if (y == game->map_height - 1)
	{
		if (x == 0)
			render_sprite(game, _wall_bottom_left, x, y);
		else if (x == game->map_width - 1)
			render_sprite(game, _wall_bottom_right, x, y);
		else
			render_sprite(game, _wall_top1, x, y); // alternate
	}
	// middle left or right
	else if (x == 0 || x == game->map_width - 1)
	{
		if (x == 0)
			render_sprite(game, _wall_middle_left1, x, y); // alternate
		else
			render_sprite(game, _wall_middle_right1, x, y); // alternate
	}
	else
		render_sprite(game, _wall_inside, x, y);
}
