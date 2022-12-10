/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:43:53 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/10 13:59:37 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

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
