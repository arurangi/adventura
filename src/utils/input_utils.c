/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:06:13 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/13 20:16:30 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_walkable(t_game *game, char ch)
{
	if (ch == '0' || ch == 'C' || ch == 'P' || ch == 'T'
		|| ch == 'E')
	{
		game->movements += 1;
		ft_printf("steps: %d\n", game->movements);
		return (1);
	}
	if (ch == 'N')
		game->life_points -= 1;
	return (0);
}

int	is_walkable_enemy(char ch)
{
	if (ch == '0' || ch == 'P' || ch == 'E' || ch == 'N')
	{
		return (1);
	}
	return (0);
}

void	move(t_game *game, int keysym, int x, int y)
{
	if (keysym == LEFT)
	{
		game->plr_angle = 18;
		if (is_walkable(game, game->map[y][x - VELOCITY]))
			game->x_shift -= VELOCITY;
	}
	if (keysym == RIGHT)
	{
		game->plr_angle = 19;
		if (is_walkable(game, game->map[y][x + VELOCITY]))
			game->x_shift += VELOCITY;
	}
	if (keysym == DOWN)
	{
		game->plr_angle = 16;
		if (is_walkable(game, game->map[y + VELOCITY][x]))
			game->y_shift += VELOCITY;
	}
	if (keysym == UP)
	{
		game->plr_angle = 17;
		if (is_walkable(game, game->map[y - VELOCITY][x]))
			game->y_shift -= VELOCITY;
	}
}
