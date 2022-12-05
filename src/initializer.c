/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/05 14:40:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Initialized the game environment
 *
 * - initialize minilibx, open a window, 
 * - check arguments, file extension and check map
 * - load assets
 * - initialize player position and movement count 
*/

#include "../so_long.h"

int	init_game_environment(t_game *game, int ac, char **av)
{
	if (ac != 2 || invalid_extension(av[1]))
		return (game_error("\033[30m:usage\033[0m ./so_long <map-path>.ber"));
	game->map_filepath = av[1];
	if (map_checker(game) == 0)
		return (0);

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (game_error("can't initialize minilibx"));

	game->window = mlx_new_window(game->mlx, game->map_width * TILE, 
		game->map_height * TILE + HUD, "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (game_error("can't initialize window"));
	}

	load_assets(game);

	game->x_shift = game->starting_pos.col;
	game->y_shift = game->starting_pos.row;
	game->angle = 7;
	game->movements = 0;
	
	return (0);
}
