/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/06 14:56:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Launch the game
 *
 * - initialize the environment
 * - handle hooks
 * - start the game loop
*/

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	int			status;

	if (ac != 2 || invalid_extension(av[1]))
		return (error_msg(1, ":usage ./so_long <map-path>.ber"));
	
	status = game_init(&game, av);
	if (status == 0)
	{
		game_over(&game);
		return (error_msg(1, "couldn't initialize the environment."));
	}
	start_game(&game);
	return (0);
}

void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->window, KEYPRESS, KEYPRESS_MASK, &handle_input, game);
	mlx_hook(game->window, DESTROY_NOTIFY, LEAVE_WINDOW_MASK, &game_over, game);
	mlx_loop(game->mlx);
}
