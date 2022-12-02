/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/02 12:19:56 by arurangi         ###   ########.fr       */
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

	// Initialize environment
	status = init_game_environment(&game, argc, argv);
	if (status == 1)
		return (game_error("couldn't initialize the environment."));

	// Launch game
	if (map_is_valid(&game))
	{
		/* Initialize Image */
		game.image.img = mlx_new_image(game.mlx, W_WIDTH, W_HEIGHT);
		game.image.data = mlx_get_data_addr(game.image.img, &game.image.bpp, &game.image.line_len, &game.image.endian);

		/* Loop & update rendering */
		mlx_loop_hook(game.mlx, &render, &game);
		/* Take user input */
		mlx_hook(game.window, 2, 1L<<0, &handle_input, &game);
		/* Loop the game */
		mlx_loop(game.mlx);
	}
	/* Execute this if all window closed */
	mlx_destroy_image(game.mlx, game.image.img);
	mlx_destroy_window(game.mlx, game.window);
	free(game.mlx);

	return (0);
}
