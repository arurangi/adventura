/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/05 16:37:46 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../so_long.h"

int    render(t_game *game)
{
    int y;
    int x;
	
	// Clear previous window
	mlx_clear_window(game->mlx, game->window);
	// Render new window: sprites
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_sprite(game, '0', x, y);
			if (game->map[y][x] == '1')
				render_sprite(game, '1', x, y);
			if (game->map[y][x] == 'C')
				render_sprite(game, 'C', x, y);
			if (game->map[y][x] == 'E')
				render_sprite(game, 'E', x, y);
			if (y == 0)
				render_sprite(game, 'L', x, y);
			x++;
		}
		y++;
	}
    render_sprite(game, 'P', game->x_shift, game->y_shift);
	// Render new window: HUD
	mlx_string_put(game->mlx, game->window, 150, 12, encode_rgb(255, 255, 255), ft_itoa(game->movements));
	mlx_string_put(game->mlx, game->window, 15, 12, encode_rgb(255, 255, 255), "Steps count: ");
	return (0);
}

/*
 * Display a given sprite based on character input
 */

void	render_sprite(t_game *game, char asset, int x, int y)
{
	void	*img_ptr;
	
	if (asset == 'P')
	{
		img_ptr = game->sprites[game->angle].img;
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, x * TILE, y * TILE + HUD);
	}
	else if (asset == 'L')
	{
		img_ptr = game->sprites[15].img;
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, x * TILE, y * TILE);
	}
	else
	{
		if (asset == '0')
			img_ptr = game->sprites[0].img;
		else if (asset == '1')
			img_ptr = game->sprites[1].img;
		else if (asset == 'C')
			img_ptr = game->sprites[4].img;
		else if (asset == 'E')
			img_ptr = game->sprites[5].img;
		else if (asset == 'N')
			img_ptr = game->sprites[11].img;
		else
			return ;
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, x * TILE, y * TILE + HUD);
	}
}
