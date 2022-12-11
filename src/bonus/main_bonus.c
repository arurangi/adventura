/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/11 19:01:12 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Launch the game
 *
 * - initialize the environment
 * - handle hooks
 * - start the game loop
*/

#include "../../so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game		game;
	int			status;

	if (ac != 2 || invalid_extension(av[1]))
		return (error_msg(1, ":usage ./so_long <map-path>.ber"));
	status = game_init(&game, av);
	if (status == 0)
	{
		error_msg(1, "couldn't initialize the environment.");
		end_game(&game);
	}
	start_game(&game);
	return (0);
}

void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->window, keypress, keypress_mask, &handle_input, game);
	mlx_hook(game->window, destroy_notify, leave_window_mask, &end_game, game);
	mlx_loop(game->mlx);
}
