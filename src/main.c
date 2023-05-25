/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/22 09:06:19 by lupin            ###   ########.fr       */
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
		error_msg(1, "couldn't initialize the environment.");
		end_game(&game);
	}
	start_game(&game);
	return (0);
}

void	start_game(t_game *game)
{
	process_input(game);
	render_and_update(game);
	mlx_loop(game->mlx);
}
