/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/02 16:30:25 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * so_long()
 *
 * Creating a 2D game
 * 
*/

#include "../so_long.h"

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
	char *path = "assets/sprites/empty_space.xpm";

	image.img = mlx_xpm_file_to_image(game.mlx, path, &image.width, &image.height);
	if (image.img == NULL)
		return (game_error("couldn't create image"));
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);

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
