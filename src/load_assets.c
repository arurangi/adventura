/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:20 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/04 10:03:49 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Load all assets (10) so they're ready for use/call
*/

#include "../so_long.h"

void	load_assets(t_game *game)
{
	char	*path[10];
	int		i;
	
	path[0] = "assets/sprites/empty_space.xpm";
	path[1] = "assets/sprites/wall.xpm";
	path[2] = "assets/sprites/exit.xpm";
	path[3] = "assets/sprites/collectible.xpm";
	path[4] = "assets/sprites/player_idle.xpm";
	path[5] = "assets/sprites/player_LF.xpm";
	path[6] = "assets/sprites/player_RF.xpm";
	path[7] = "assets/sprites/enemy_idle.xpm";
	path[8] = "assets/sprites/enemy_LF.xpm";
	path[9] = "assets/sprites/enemy_RF.xpm";
	
	i = 0;
	while (i < 10)
	{
		game->sprites[i].img = mlx_xpm_file_to_image(game->mlx, path[i],
			&game->sprites[i].width, &game->sprites[i].height);
		if (game->sprites[i].img == NULL)
			game_error("couldn't create image");
		game->sprites[i].addr = mlx_get_data_addr(game->sprites[i].img, 
			&game->sprites[i].bpp, &game->sprites[i].line_len,
				&game->sprites[i].endian);
		i++;
	}
}

void	render_sprite(t_game game, char asset, int x, int y)
{
	void	*img_ptr;
	
	if (asset == '1')
		img_ptr = game.sprites[1].img;
	else if (asset == '0')
		img_ptr = game.sprites[0].img;
	else if (asset == 'C')
		img_ptr = game.sprites[3].img;
	else if (asset == 'P')
		img_ptr = game.sprites[4].img;
	else if (asset == 'E')
		img_ptr = game.sprites[2].img;
	else if (asset == 'N')
		img_ptr = game.sprites[7].img;
	else
		return ;
	mlx_put_image_to_window(game.mlx, game.window, img_ptr, x * TILE, y * TILE);
}