/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 13:53:22 by Arsene           ###   ########.fr       */
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

	/* Initialize environment (args, map, minilibx, window) */
	status = init_game_environment(&game, argc, argv);
	if (status == 1)
		return (game_error("couldn't initialize the environment."));
	
	/* Render the map */
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.window, 2, 1L<<0, &handle_input, &game);

	/* Game loop */
	mlx_loop(game.mlx);
	return (1);
}
