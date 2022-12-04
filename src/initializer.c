/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 16:57:31 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	load_assets()
// {
// 	t_img	image;
	
// 	char *path = "assets/sprites/empty_space.xpm";

// 	image.img = mlx_xpm_file_to_image(game.mlx, path, &image.width, &image.height);
// 	if (image.img == NULL)
// 		return (game_error("couldn't create image"));
// 	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);
// }

int	init_game_environment(t_game *game, int ac, char **av)
{
	// Check arguments & File extension
	if (ac != 2 || invalid_extension(av[1]))
		return (game_error("\033[30m:usage\033[0m ./so_long <map-path>.ber"));
	game->map_filepath = av[1];
	if (map_checker(game) == 0)
		return (0);

	// Launch minilibx library
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (game_error("can't initialize minilibx"));

	// Get window's pointer
	game->window = mlx_new_window(game->mlx, game->map_width * TILE, 
		game->map_height * TILE, "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (game_error("can't initialize window"));
	}

	// Load assets
	load_assets(game);

	// Initialize player position
	game->x_shift = game->starting_pos.col;
	game->y_shift = game->starting_pos.row;
	game->movements = 0;
	
	return (0);
}