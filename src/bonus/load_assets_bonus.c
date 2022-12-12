/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/12 14:12:40 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../../so_long_bonus.h"

int	load_assets(t_game *game)
{
	game->sprites[0].path = "assets/sprites/bonus/empty_space.xpm";
	game->sprites[1].path = "assets/sprites/bonus/wall.xpm";
	game->sprites[2].path = "assets/sprites/bonus/wall_top_left.xpm";
	game->sprites[3].path = "assets/sprites/bonus/wall_top_right.xpm";
	game->sprites[4].path = "assets/sprites/bonus/wall_bottom_left.xpm";
	game->sprites[5].path = "assets/sprites/bonus/wall_bottom_right.xpm";
	game->sprites[6].path = "assets/sprites/bonus/wall_top1.xpm";
	game->sprites[7].path = "assets/sprites/bonus/wall_top2.xpm";
	game->sprites[8].path = "assets/sprites/bonus/wall_middle_left1.xpm";
	game->sprites[9].path = "assets/sprites/bonus/wall_middle_left2.xpm";
	game->sprites[10].path = "assets/sprites/bonus/wall_middle_right1.xpm";
	game->sprites[11].path = "assets/sprites/bonus/wall_middle_right2.xpm";
	game->sprites[12].path = "assets/sprites/bonus/coins.xpm";
	game->sprites[13].path = "assets/sprites/bonus/treasure_chest.xpm";
	game->sprites[14].path = "assets/sprites/bonus/exit_closed.xpm";
	game->sprites[15].path = "assets/sprites/bonus/exit_opened.xpm";
	game->sprites[16].path = "assets/sprites/bonus/player_down.xpm";
	game->sprites[17].path = "assets/sprites/bonus/player_up.xpm";
	game->sprites[18].path = "assets/sprites/bonus/player_left.xpm";
	game->sprites[19].path = "assets/sprites/bonus/player_right.xpm";
	game->sprites[20].path = "assets/sprites/bonus/enemy_0.xpm";
	game->sprites[21].path = "assets/sprites/bonus/enemy_1.xpm";
	game->sprites[22].path = "assets/sprites/bonus/enemy_2.xpm";
	game->sprites[23].path = "assets/sprites/bonus/enemy_3.xpm";
	return (save_assets(game));
}

void	load_heart(t_game *game)
{
	game->sprites[24].path = "assets/sprites/bonus/health_0.xpm";
	game->sprites[25].path = "assets/sprites/bonus/health_10.xpm";
	game->sprites[26].path = "assets/sprites/bonus/health_25.xpm";
	game->sprites[27].path = "assets/sprites/bonus/health_50.xpm";
	game->sprites[28].path = "assets/sprites/bonus/health_75.xpm";
	game->sprites[29].path = "assets/sprites/bonus/health_100.xpm";
	game->sprites[30].path = "assets/sprites/bonus/footsteps.xpm";
}

int	save_assets(t_game *game)
{
	int	i;

	i = 0;
	load_heart(game);
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
