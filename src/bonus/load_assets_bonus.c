/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/08 12:11:03 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../../so_long_bonus.h"

int	load_assets(t_game *game)
{
	char	*path[20];

	path[0] = "assets/sprites/bonus/empty_space.xpm";
	path[1] = "assets/sprites/bonus/wall.xpm";
	path[2] = "assets/sprites/bonus/wall_top_left.xpm";
	path[3] = "assets/sprites/bonus/wall_top_right.xpm";
	path[4] = "assets/sprites/bonus/wall_bottom_left.xpm";
	path[5] = "assets/sprites/bonus/wall_bottom_right.xpm";
	path[6] = "assets/sprites/bonus/wall_top1.xpm";
	path[7] = "assets/sprites/bonus/wall_top2.xpm";
	path[8] = "assets/sprites/bonus/wall_middle_left1.xpm";
	path[9] = "assets/sprites/bonus/wall_middle_left2.xpm";
	path[10] = "assets/sprites/bonus/wall_middle_right1.xpm";
	path[11] = "assets/sprites/bonus/wall_middle_right2.xpm";
	path[12] = "assets/sprites/bonus/coins.xpm";
	path[13] = "assets/sprites/bonus/treasure_chest.xpm";
	path[14] = "assets/sprites/bonus/exit_closed.xpm";
	path[15] = "assets/sprites/bonus/exit_opened.xpm";
	path[16] = "assets/sprites/bonus/player_down.xpm";
	path[17] = "";
	path[18] = "";
	path[19] = "";
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
