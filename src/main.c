/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/03 22:07:29 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * so_long()
 *
 * Creating a 2D game
 * 
*/

#include "../so_long.h"

void	load_sprites()
{
	char *path[10];
	
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
	
	image.img = mlx_xpm_file_to_image(game.mlx, path, &image.width, &image.height);
	if (image.img == NULL)
		return (game_error("couldn't create image"));
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			status;
	t_img		image;

	// Initialize environment (args, map, minilibx, window)
	status = init_game_environment(&game, argc, argv);
	if (status == 1)
		return (game_error("couldn't initialize the environment."));

	// Print an image
	load_assets();

	
	
	int y = 0;
	while (y < game.map_height)
	{
		int x = 0;
		while (x < game.map_width)
		{
			mlx_put_image_to_window(game.mlx, game.window, image.img, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	mlx_loop(game.mlx);
	return (0);
}
