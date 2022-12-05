/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/05 15:23:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../so_long.h"

void	load_assets(t_game *game)
{
	char	*path[16];
	int		i;

	// Empty space
	path[0] = "assets/sprites/empty_space.xpm";
	// Walls
	path[1] = "assets/sprites/wall.xpm";
	path[2] = "assets/sprites/wall_2.xpm";
	path[3] = "assets/sprites/wall_3.xpm";
	// Collectibles
	path[4] = "assets/sprites/collectible.xpm";
	// Exit
	path[5] = "assets/sprites/exit_closed.xpm";
	path[6] = "assets/sprites/exit_opened.xpm";
	// Player
	path[7] = "assets/sprites/player_down.xpm";
	path[8] = "assets/sprites/player_up.xpm";
	path[9] = "assets/sprites/player_left.xpm";
	path[10] = "assets/sprites/player_right.xpm";
	// Enemy
	path[11] = "assets/sprites/enemy_down.xpm"; 
	path[12] = "assets/sprites/enemy_up.xpm";
	path[13] = "assets/sprites/enemy_left.xpm";
	path[14] = "assets/sprites/enemy_right.xpm";
	// HUD
	path[15] = "assets/sprites/board.xpm";

	i = 0;
	while (i < 16)
	{
		game->sprites[i].img = mlx_xpm_file_to_image(game->mlx, path[i],
			&game->sprites[i].width, &game->sprites[i].height);
		if (game->sprites[i].img == NULL)
			game_error("couldn't create image \033[35m%s\033[0m", path[i]);
		game->sprites[i].addr = mlx_get_data_addr(game->sprites[i].img, 
			&game->sprites[i].bpp, &game->sprites[i].line_len,
				&game->sprites[i].endian);
		i++;
	}
}

/*

- player (down) (up) (left) (right)
- enemy (down) (up) (left) (right)
- exit (closed) (opened)

*/