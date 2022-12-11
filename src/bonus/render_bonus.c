/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/11 20:56:03 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../../so_long_bonus.h"

int	render(t_game *game)
{
	int	row;
	int	col;

	mlx_clear_window(game->mlx, game->window);
	render_hud(game);
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
	render_sprite(game, game->plr_angle, game->x_shift, game->y_shift);
	return (0);
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
		animate(game, col, row);
}
