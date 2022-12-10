/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/10 15:38:22 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * save every sprites and their data
 * in an array for later use
*/

#include "../../so_long.h"

int	load_assets(t_game *game)
{
	char	*path[6];

	path[0] = "assets/sprites/empty_space.xpm";
	path[1] = "assets/sprites/wall.xpm";
	path[2] = "assets/sprites/collectible.xpm";
	path[3] = "assets/sprites/exit_closed.xpm";
	path[4] = "assets/sprites/exit_opened.xpm";
	path[5] = "assets/sprites/player_down.xpm";
	return (save_assets(game, path));
}

int	save_assets(t_game *game, char **path)
{
	int	i;

	i = 0;
	while (i < 6)
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
	while (i < 6)
	{
		free(game->sprites[i].img);
		i++;
	}
}
