/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/06 15:16:58 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../so_long.h"

int    render(t_game *game)
{
    int y;
    int x;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_sprite(game, '0', x, y);
			if (game->map[y][x] == '1')
				render_sprite(game, '1', x, y);
			if (game->map[y][x] == 'C')
				render_sprite(game, 'C', x, y);
			if (game->map[y][x] == 'E')
				render_sprite(game, 'E', x, y);
			if (y == 0)
				render_sprite(game, 'L', x, y);
			x++;
		}
		y++;
	}
    render_sprite(game, 'P', game->x_shift, game->y_shift);
	render_HUD(game);
	return (0);
}
