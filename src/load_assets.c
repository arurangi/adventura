/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/30 19:51:46 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "so_long.h"

int	load_assets(t_game *game)
{
	game->sprites[0].path = "assets/sprites/empty_space.xpm";
	
	game->sprites[1].path = "assets/sprites/wall.xpm";
	game->sprites[2].path = "assets/sprites/wall_top_left.xpm";
	game->sprites[3].path = "assets/sprites/wall_top_right.xpm";
	game->sprites[4].path = "assets/sprites/wall_bottom_left.xpm";
	game->sprites[5].path = "assets/sprites/wall_bottom_right.xpm";
	game->sprites[6].path = "assets/sprites/wall_top1.xpm";
	game->sprites[7].path = "assets/sprites/wall_top2.xpm";
	game->sprites[8].path = "assets/sprites/wall_middle_left1.xpm";
	game->sprites[9].path = "assets/sprites/wall_middle_left2.xpm";
	game->sprites[10].path = "assets/sprites/wall_middle_right1.xpm";
	game->sprites[11].path = "assets/sprites/wall_middle_right2.xpm";
	
	game->sprites[12].path = "assets/sprites/coins.xpm";
	game->sprites[13].path = "assets/sprites/treasure_chest.xpm";
	
	game->sprites[14].path = "assets/sprites/exit_closed.xpm";
	game->sprites[15].path = "assets/sprites/exit_opened.xpm";
	
	game->sprites[16].path = "assets/sprites/player_down.xpm";
	game->sprites[17].path = "assets/sprites/player_up.xpm";
	game->sprites[18].path = "assets/sprites/player_left.xpm";
	game->sprites[19].path = "assets/sprites/player_right.xpm";
	
	game->sprites[20].path = "assets/sprites/enemy_0.xpm";
	game->sprites[21].path = "assets/sprites/enemy_1.xpm";
	game->sprites[22].path = "assets/sprites/enemy_2.xpm";
	game->sprites[23].path = "assets/sprites/enemy_3.xpm";

	game->sprites[24].path = "assets/sprites/health_0.xpm";
	game->sprites[25].path = "assets/sprites/health_10.xpm";
	game->sprites[26].path = "assets/sprites/health_25.xpm";
	game->sprites[27].path = "assets/sprites/health_50.xpm";
	game->sprites[28].path = "assets/sprites/health_75.xpm";
	game->sprites[29].path = "assets/sprites/health_100.xpm";
	
	game->sprites[30].path = "assets/sprites/footsteps.xpm";

	game->sprites[31].path = "assets/ui/game_over.xpm";
	return (save_assets(game));
}

int	save_assets(t_game *game)
{
	int	i;

	i = 0;
	while (i < SPRITES_NBR)
	{
		game->sprites[i].img = mlx_xpm_file_to_image(game->mlx,
				game->sprites[i].path,
				&game->sprites[i].width,
				&game->sprites[i].height);
		if (game->sprites[i].img == NULL)
			return (error_msg(0, "can't save asset: %s",
					game->sprites[i].path));
		i++;
	}
	return (1);
}
