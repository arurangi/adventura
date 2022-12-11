/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/11 15:38:41 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../../so_long.h"

int	load_assets(t_game *game)
{
	game->sprites[0].path = "assets/sprites/empty_space.xpm";
	game->sprites[1].path = "assets/sprites/wall.xpm";
	game->sprites[2].path = "assets/sprites/collectible.xpm";
	game->sprites[3].path = "assets/sprites/exit_closed.xpm";
	game->sprites[4].path = "assets/sprites/exit_opened.xpm";
	game->sprites[5].path = "assets/sprites/player_down.xpm";
	return (save_assets(game));
}

int	save_assets(t_game *game)
{
	int	i;

	i = 0;
	while (i < SPRITES_NBR)
	{
		game->sprites[i].img = mlx_xpm_file_to_image(game->mlx,
				game->sprites[i].path, &game->sprites[i].width,
				&game->sprites[i].height);
		if (game->sprites[i].img == NULL)
			return (error_msg(0, "can't save asset: %s",
					game->sprites[i].path));
		i++;
	}
	return (1);
}
