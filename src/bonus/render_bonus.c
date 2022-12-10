/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/10 12:07:55 by arurangi         ###   ########.fr       */
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
	render_hud(game);
	game->delay += 1;
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
	return (0);
}
