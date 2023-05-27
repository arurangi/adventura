/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:43:53 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:29:05 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_walls(t_game *game, int x, int y)
{
	if (x == 0)
		render_sprite(game, _wall_top_left, x, y);
	else if (x == game->map_width - 1)
		render_sprite(game, _wall_top_right, x, y);
	else
		render_sprite(game, _wall_top1, x, y);
}

void	bottom_walls(t_game *game, int x, int y)
{
	if (x == 0)
		render_sprite(game, _wall_bottom_left, x, y);
	else if (x == game->map_width - 1)
		render_sprite(game, _wall_bottom_right, x, y);
	else
		render_sprite(game, _wall_top1, x, y);
}

void	inner_walls(t_game *game, int x, int y)
{
	if (x == 0)
		render_sprite(game, _wall_middle_left1, x, y);
	else
		render_sprite(game, _wall_middle_right1, x, y);
}
