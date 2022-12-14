/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:40:36 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/14 11:45:59 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 
*/

#include "../so_long.h"

void	animate(t_game *game, int x, int y)
{
	int	frame;

	frame = game->state;
	render_sprite(game, frame + 20, x, y);
	if (is_walkable_enemy(game, y, x + (1 * game->polarity)))
	{
		if (game->delay % 31 == 30)
		{
			game->map[y][x] = '0';
			game->map[y][x + (1 * game->polarity)] = 'N';
		}
	}
	else
	{
		game->polarity *= -1;
		// + change sprite angle
	}
	add_delay(game, frame);
}

void	add_delay(t_game *game, int frame)
{
	game->delay += 1;
	if (game->delay % 11 == 10)
		game->state = (frame + 1) % 4;
	usleep(10);
}
