/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:22:42 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Launch the game
 *
 * - initialize the environment
 * - start the game loop
*/

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2 || invalid_extension(av[1]))
		return (error_msg(EXIT_FAILURE, ":usage ./so_long <map-path>.ber"));
	if (!game_init(&game, av))
	{
		error_msg(EXIT_FAILURE, "couldn't initialize the environment.");
		end_game(&game);
	}
	start_game(&game);
	return (EXIT_SUCCESS);
}

void	start_game(t_game *game)
{
	render_hud(game);
	draw_map(game);
	process_input(game);
	render_and_update(game);
	mlx_loop(game->mlx);
}
