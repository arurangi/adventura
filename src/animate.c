/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:40:36 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:28:33 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 
*/

#include "so_long.h"

void	animate(t_game *game, int x, int y)
{
	int	frame;

	frame = game->animation_state;
	render_sprite(game, frame + FIRST_FRAME_INDEX, x, y);
	game->delay += 1;
	if (game->delay % STATE_PERIOD == STATE_PERIOD - 1)
		game->animation_state = (frame + 1) % NBR_OF_FRAMES;
	usleep(1000);
}

void	add_delay(t_game *game, int frame)
{
	game->delay += 1;
	if (game->delay % STATE_PERIOD == STATE_PERIOD - 1)
		game->animation_state = (frame + 1) % NBR_OF_FRAMES;
}

int	animation_delay(t_game *game)
{
	game->delay += 1;
	if (game->delay % STATE_PERIOD == STATE_PERIOD - 1)
		return (1);
	return (0);
}
