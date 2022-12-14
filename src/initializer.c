/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/14 19:33:13 by Arsene           ###   ########.fr       */
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

int	game_init(t_game *game, char **av)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (error_msg(0, "can't initialize minilibx"));

	game->window = NULL;
	game->sprites[0].img = NULL;

	map_init(game, av);
	if (map_checker(game) == 0)
		return (0);

	game->window = mlx_new_window(game->mlx, game->map_width * TILE,
			game->map_height * TILE + (HUD + 40), "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (error_msg(0, "couldn't connect to the window"));
	}
	game->error_count = 0;
	player_init(game);\
	
	load_enemies(game);

	if (game->error_count)
		return (0);
	game->delay = 0;
	game->state = 0;
	game->polarity = 1;

	return (load_assets(game));
}

void	load_enemies(t_game *game)
{
	if (game->n_credit == 0)
		return ;

	game->enemies = malloc(sizeof(t_actor) * game->n_credit);
	if (game->enemies == NULL)
	{
		error_msg(0, "can't allocate memory to enemies");
		return ;
	}

	enemy_init(game);
}

void	enemy_init(t_game *game)
{
	int row;
	int col;
	int n_id;
	int	status;

	status = 1;
	n_id = 0;
	row = 0;
	// Initialize all enemy parameters (coordinates, assets, image pointer)
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			if (game->map[row][col] == 'N')
			{
				game->enemies[n_id].x = col;
				game->enemies[n_id].y = row;
				game->enemies[n_id].frame_pos = 0;
				game->enemies[n_id].polarity = 1;
				locate_enemy_assets(game, n_id);
				status = save_enemy_data(game, n_id);
				if (status == 0)
					return ;
				n_id++;
			}
			col++;
		}
		// Early exit to avoid searching after all enemies have been found
		if (n_id == game->n_credit - 1)
			break ;
		row++;
	}
}

void	map_init(t_game *game, char **av)
{
	game->map_filepath = av[1];
	game->c_credit = 0;
	game->e_credit = 0;
	game->p_credit = 0;
	game->n_credit = 0;
	game->map_width = -1;
}

void	player_init(t_game *game)
{
	game->x_shift = game->starting_pos.col;
	game->y_shift = game->starting_pos.row;
	game->plr_angle = 16;
	game->movements = 0;
	game->life_points = 5;
}

