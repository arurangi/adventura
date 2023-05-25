/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:15:51 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/25 18:12:19 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_sprite(t_game *game, int asset, int col, int row)
{
	void	*img_ptr;

	img_ptr = game->sprites[asset].img;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, col * TILE_SIZE, row * TILE_SIZE + HUD_HEIGHT);
	mlx_do_sync(game->mlx);
}

void	render_hud(t_game *game)
{
	int		i;
	void	*img_ptr;
	char	*hud_data[2];

	// Draw black borders around the map
	i = 0;
	img_ptr = game->sprites[_wall_inside].img;
	while (i < game->map_width * TILE_SIZE)
	{
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i, 0); 			// first row of HUD
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i, TILE_SIZE);	// second row of HUD
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i,
			game->map_height * TILE_SIZE + HUD_HEIGHT);								// bottom map row
		i += TILE_SIZE;
	}
	
	hud_data[0] = ft_itoa(game->steps_count);
	hud_data[1] = ft_itoa(game->life_points);
	
	// Life points
	mlx_put_image_to_window(game->mlx, game->window,								// draw heart
		game->sprites[game->life_points + 24].img, TILE_SIZE, 20);
	mlx_string_put(game->mlx, game->window,											// write life pointa
		TILE_SIZE * 2, HUD_HEIGHT - 50, rgbify(255, 255, 255), hud_data[1]);

	// Step counts
	mlx_put_image_to_window(game->mlx, game->window,								// draw steps
		game->sprites[30].img, TILE_SIZE * 3, 20);
	mlx_string_put(game->mlx, game->window,											// write steps count
		TILE_SIZE * 3 + 40, HUD_HEIGHT - 50, rgbify(255, 255, 255), hud_data[0]);

	free_hud(hud_data);
}

void	render_hud_values(t_game *game)
{
	char	*hud_data[2];
	void	*img_ptr;

	hud_data[0] = ft_itoa(game->steps_count);
	hud_data[1] = ft_itoa(game->life_points);
	
	// Paint black
	img_ptr = game->sprites[_wall_inside].img;
	mlx_put_image_to_window(game->mlx, game->window, img_ptr, TILE_SIZE + 35, HUD_HEIGHT - 75);
	mlx_put_image_to_window(game->mlx, game->window, img_ptr, TILE_SIZE * 4 - 4, HUD_HEIGHT - 75);
	// Print life points
	mlx_string_put(game->mlx, game->window,
		TILE_SIZE * 2, HUD_HEIGHT - 50, rgbify(255, 255, 255), hud_data[1]);
	// Print steps count
	mlx_string_put(game->mlx, game->window,
		TILE_SIZE * 3 + 40, HUD_HEIGHT - 50, rgbify(255, 255, 255), hud_data[0]);
	free_hud(hud_data);
}

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	identify_walls(t_game *game, int x, int y)
{
	if (y == 0)
		top_walls(game, x, y);
	else if (y == game->map_height - 1)
		bottom_walls(game, x, y);
	else if (x == 0 || x == game->map_width - 1)
		inner_walls(game, x, y);
	else
		render_sprite(game, _wall_inside, x, y);
}

// Check whether exit is opened or closed
void	identify_exit(t_game *game, int x, int y)
{
	if (game->c_credit == 0)
		render_sprite(game, _exit_opened, x, y);
	else
		render_sprite(game, _emptyspace, x, y);
}
