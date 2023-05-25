/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/25 16:22:17 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Launch the game
 *
 * - initialize the environment
 * - start the game loop
*/

#include "../so_long.h"

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

void	draw_map(t_game *game)
{
	int row, col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			switch (game->map[row][col])
			{
				case '1':
					identify_walls(game, col, row);
					break ;
				case 'E':
					render_sprite(game, _exit_closed, col, row);
					break ;
				case 'C':
					render_sprite(game, _coins, col, row);
					break ;
				case 'T':
					render_sprite(game, _treasure_chest, col, row);
					break ;
				case 'N':
					render_sprite(game, _enemy1, col, row);
					break ;
				default :
					render_sprite(game, _emptyspace, col, row);
					break ;
			}
			col++;
		}
		row++;
	}
}

void	start_game(t_game *game)
{
	render_hud(game);
	draw_map(game);
	process_input(game);
	render_and_update(game);
	mlx_loop(game->mlx);
}
