/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/30 13:39:57 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * so_long()
 *
 * Creating a 2D game
 * 
*/

#include "../so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_printf("%d\n", keysym);
	return (0);
}



int	main(int argc, char **argv)
{
	t_game		game;
	
	// Initialize the environment
	if (argc != 2 || invalid_extension(argv[1]))
	{
		write(1, "Usage: ./so_long <map-path>.ber\n", 32);
		return (1);
	}
	game.map_filepath = argv[1];
	
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_printf("Lib error: can't initialize minilibx");
		return (1);
	}

	game.window = mlx_new_window(game.mlx, W_WIDTH, W_HEIGHT, "Adventura");
	if (game.window == NULL)
	{
		free(game.window);
		return (1);
	}

	// Launch game
	if (map_is_valid(&game))
	{
		/* Setup hooks */
		game.img.mlx_img = mlx_new_image(game.mlx, W_WIDTH, W_HEIGHT);
		game.img.addr = mlx_get_data_addr(game.img.mlx_img, &game.img.bpp,
			&game.img.line_len, &game.img.endian);
		
		mlx_loop_hook(game.mlx, &render, &game);
		mlx_hook(game.window, 2, 1L<<0, &handle_input, &game);
		
		mlx_loop(game.mlx);
	}
	/* Execute this if all window closed */
	mlx_destroy_image(game.mlx, game.img.mlx_img);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	
	return (0);
}
