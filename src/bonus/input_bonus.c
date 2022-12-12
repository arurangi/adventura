/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/12 11:19:47 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle user input {W, S, A, D} to have ability to
 * move in all directions within the walls
*/

#include "../../so_long_bonus.h"

int	handle_input(int keysym, t_game *game)
{
	int	*x;
	int	*y;

	x = &game->x_shift;
	y = &game->y_shift;
	if (!game)
		return (error_msg(0, "game struct missing, can't handle input"));
	if (keysym == LEFT || keysym == RIGHT || keysym == UP || keysym == DOWN)
		move(game, keysym, game->x_shift, game->y_shift);
	if (keysym == ESC || game->life_points == 0
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
