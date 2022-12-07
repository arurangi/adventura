/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:10:47 by Arsene           ###   ########.fr       */
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

#include "../../so_long.h"

int	game_init(t_game *game, char **av)
{
	// Map
	game->c_credit = 0;
	game->e_credit = 0;
	game->p_credit = 0;
	game->map_width = -1;
	
	game->map_filepath = av[1];
	if (map_checker(game) == 0)
		return (0);

	// Player 
	game->x_shift = game->starting_pos.col * TILE;
	game->y_shift = game->starting_pos.row * TILE + HUD;
	game->angle = 7;
	game->movements = 0;

	// Environment
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (error_msg(0, "can't initialize minilibx"));

	game->window = mlx_new_window(game->mlx, game->map_width * TILE, 
		game->map_height * TILE + HUD, "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (error_msg(0, "can't initialize window"));
	}
	
	// Assets
	load_assets(game);
	return (1);
}

