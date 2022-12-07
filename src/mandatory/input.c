/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 12:04:10 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle user input {W, S, A, D} to have ability to
 * move in all directions within the walls
*/

#include "../../so_long.h"

int	handle_input(int keysym, t_game *game)
{
	int	*x;
	int	*y;

	x = &game->x_shift;
	y = &game->y_shift;
	if (!game)
		return (error_msg(0, "game struct missing, can't handle input"));
	if (keysym == ESC)
		game_over(game);
	if (keysym == LEFT || keysym == RIGHT || keysym == UP || keysym == DOWN)
		move(game, keysym);
	if (game->map[*y][*x] == 'C')
	{
		game->map[*y][*x] = '0';
		game->c_credit -= 1;
	}
	if (game->map[*y][*x] == 'E' && game->c_credit == 0)
	{
		game->map[*y][*x] = '0';
		game_over(game);
	}
	ft_printf("Moves: %d\n", game->movements);
	return (0);
}

void	move(t_game *game, int keysym)
{
	int	x;
	int	y;
	
	x = game->x_shift;
	y = game->y_shift;
	if (keysym == LEFT && is_walkable(game, game->map[y][x - VELOCITY]))
		game->x_shift -= VELOCITY;
	if (keysym == RIGHT && is_walkable(game, game->map[y][x + VELOCITY]))
		game->x_shift += VELOCITY;
	if (keysym == DOWN && is_walkable(game, game->map[y + VELOCITY][x]))
		game->y_shift += VELOCITY;
	if (keysym == UP && is_walkable(game, game->map[y - VELOCITY][x]))
		game->y_shift -= VELOCITY;
}
