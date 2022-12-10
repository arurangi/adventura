/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/10 16:38:12 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../../so_long.h"

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
			render_sprite(game, _emptyspace, x, y);
			if (game->map[y][x] == '1')
				render_sprite(game, _wall, x, y);
			if (game->map[y][x] == 'C')
				render_sprite(game, _collectible, x, y);
			if (game->map[y][x] == 'E')
				render_sprite(game, _exit_closed, x, y);
			x++;
		}
		y++;
	}
	render_player(game, game->x_shift, game->y_shift);
	render_hud(game);
	return (0);
}
