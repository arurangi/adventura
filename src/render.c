/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/04 07:42:00 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    render(t_game game)
{
	int y = 0;
	while (y < game.map_height)
	{
		int x = 0;
		while (x < game.map_width)
		{
			render_sprite(game, '0', x, y);
			if (game.map[y][x] == '1')
				render_sprite(game, '1', x, y);
			if (game.map[y][x] == 'C')
				render_sprite(game, 'C', x, y);
			if (game.map[y][x] == 'P')
				render_sprite(game, 'P', x, y);
			if (game.map[y][x] == 'E')
				render_sprite(game, 'E', x, y);
			x++;
		}
		y++;
	}
}

// int	render(t_game *game)
// {
// 	if (game->window == NULL)
//         return (1);
        
//   render_rect(&game->image, (t_shape)
//       {0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
//   render_rect(&game->image, (t_shape)
//       { game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});

//     return (0);
// }

// render_rect(&game->image, (t_shape)
//       {0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
// render_rect(&game->image, (t_shape)
//       { game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});