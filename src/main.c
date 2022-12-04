/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 07:42:11 by Arsene           ###   ########.fr       */
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

	// Initialize environment (args, map, minilibx, window)
	status = init_game_environment(&game, argc, argv);
	if (status == 1)
		return (game_error("couldn't initialize the environment."));
	// Render the map
	render(game);
	// Loop
	mlx_loop(game.mlx);
	return (0);
}
