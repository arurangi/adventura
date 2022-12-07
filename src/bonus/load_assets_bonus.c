/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/07 16:53:40 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../../so_long_bonus.h"

int	load_assets(t_game *game)
{
	char	*path[16];

	path[0] = "assets/sprites/empty_space.xpm";
	path[1] = "assets/sprites/wall.xpm";
	path[2] = "assets/sprites/wall_2.xpm";
	path[3] = "assets/sprites/wall_3.xpm";
	path[4] = "assets/sprites/collectible.xpm";
	path[5] = "assets/sprites/exit_closed.xpm";
	path[6] = "assets/sprites/exit_opened.xpm";
	path[7] = "assets/sprites/player_down.xpm";
	path[8] = "assets/sprites/player_up.xpm";
	path[9] = "assets/sprites/player_left.xpm";
	path[10] = "assets/sprites/player_right.xpm";
	path[11] = "assets/sprites/enemy_down.xpm";
	path[12] = "assets/sprites/enemy_up.xpm";
	path[13] = "assets/sprites/enemy_left.xpm";
	path[14] = "assets/sprites/enemy_right.xpm";
	path[15] = "assets/sprites/board.xpm";
	return (save_assets(game, path));
}

int	save_assets(t_game *game, char **path)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		game->sprites[i].img = mlx_xpm_file_to_image(game->mlx, path[i],
				&game->sprites[i].width, &game->sprites[i].height);
		if (game->sprites[i].img == NULL)
			return (error_msg(0, "can't save asset: %s", path[i]));
		i++;
	}
	return (1);
}

void	free_assets(t_game *game)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->sprites[i].img);
		i++;
	}
}
