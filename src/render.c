/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/25 10:42:29 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../so_long.h"

void	render_and_update(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
}

int	render(t_game *game)
{
	int	row;
	int	col;

	render_hud(game);
	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
			identify_sprites(game, row, col++);
		row++;
	}
	render_sprite(game, game->plr_angle, game->x_shift, game->y_shift);
	update_life_points(game);
	mlx_do_sync(game->mlx);
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
	//render_sprite(game, _enemy1, col, row);
}

void	update_life_points(t_game *game)
{
	if (game->map[game->y_shift][game->x_shift] == 'N')
	{
		if ((game->delay % 21 == 20) && game->life_points > 0)
			game->life_points -= 1;
		usleep(1000);
	}
}
