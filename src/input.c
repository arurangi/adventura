/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:28:44 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle user input {W, S, A, D} to have ability to
 * move in all directions within the walls
*/

#include "so_long.h"

void	process_input(t_game *game)
{
	mlx_hook(game->window, keypress, keypress_mask, &handle_input, game);
	mlx_hook(game->window, destroy_notify, leave_window_mask, &end_game, game);
}

int	handle_input(int keysym, t_game *game)
{
	int	*x;
	int	*y;

	x = &game->x_shift;
	y = &game->y_shift;
	if (!game)
		return (error_msg(0, "game struct missing, can't handle input"));
	if (is_arrow_keys(keysym))
		move(game, keysym, game->x_shift, game->y_shift);
	if (keysym == ESC_KEY || game->life_points == 0
		|| (game->map[*y][*x] == 'E' && game->c_credit == 0))
		end_game(game);
	if (game->map[*y][*x] == 'C' || game->map[*y][*x] == 'T')
	{
		if (game->map[*y][*x] == 'C')
			game->c_credit -= 1;
		game->map[*y][*x] = '0';
	}
	return (0);
}

int	end_game(t_game *game)
{
	if (game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		//draw_black_screen(game);
		//usleep(1000000);
		mlx_destroy_window(game->mlx, game->window);
	}
	if (game->map != NULL)
		free_matrix(game->map);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
