/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:40:36 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/09 13:21:12 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 
*/

#include "../../so_long_bonus.h"

void	animate(t_game *game, int x, int y)
{
	int	frame;

	frame = game->state;
	render_sprite(game, frame + 20, x, y);
	game->state = (frame + 1) % 4;
	usleep(10000);
}
