/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/06 15:11:05 by arurangi         ###   ########.fr       */
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

	mlx_clear_window(game->mlx, game->window);
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
	render_HUD(game);
	return (0);
}

/*
 * Display a given sprite based on character input
*/

void	render_HUD(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 15, 12, rgbify(255, 255, 255), "Steps count: ");
	mlx_string_put(game->mlx, game->window, 150, 12, rgbify(255, 255, 255), ft_itoa(game->movements));
	mlx_string_put(game->mlx, game->window, 300, 12, rgbify(255, 255, 255), "Remaining items: ");
	mlx_string_put(game->mlx, game->window, 500, 12, rgbify(255, 255, 255), ft_itoa(game->c_credit));
}

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

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
