/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:15:51 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/09 10:24:13 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

void	render_sprite(t_game *game, int asset, int x, int y)
{
	void	*img_ptr;

	img_ptr = game->sprites[asset].img;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, x * TILE, y * TILE + HUD);
}

void	render_hud(t_game *game)
{
	int		i;
	void	*img_ptr;

	i = 0;
	img_ptr = game->sprites[_wall_inside].img;
	while (i < W_WIDTH)
	{
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i, 0);
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i, TILE);
		mlx_put_image_to_window(game->mlx, game->window, img_ptr, i,
			game->map_height * TILE + HUD);
		i += 40;
	}
	mlx_string_put(game->mlx, game->window,
		TILE + 20, HUD - 50, rgbify(255, 255, 255), "steps");
	mlx_string_put(game->mlx, game->window,
		TILE - 10, HUD - 50, rgbify(255, 255, 255), ft_itoa(game->movements));
	mlx_string_put(game->mlx, game->window,
		300, 30, rgbify(255, 255, 255), "Remaining items: ");
	mlx_string_put(game->mlx, game->window,
		500, 30, rgbify(255, 255, 255), ft_itoa(game->c_credit));
}

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	identify_walls(t_game *game, int x, int y)
{
	// top
	if (y == 0)
	{
		if (x == 0)
			render_sprite(game, _wall_top_left, x, y);
		else if (x == game->map_width - 1)
			render_sprite(game, _wall_top_right, x, y);
		else
			render_sprite(game, _wall_top1, x, y);
	}
	// bottom
	else if (y == game->map_height - 1)
	{
		if (x == 0)
			render_sprite(game, _wall_bottom_left, x, y);
		else if (x == game->map_width - 1)
			render_sprite(game, _wall_bottom_right, x, y);
		else
			render_sprite(game, _wall_top1, x, y); // alternate
	}
	// middle left or right
	else if (x == 0 || x == game->map_width - 1)
	{
		if (x == 0)
			render_sprite(game, _wall_middle_left1, x, y); // alternate
		else
			render_sprite(game, _wall_middle_right1, x, y); // alternate
	}
	else
		render_sprite(game, _wall_inside, x, y);
}

void	identify_exit(t_game *game, int x, int y)
{
	if (game->c_credit == 0)
		render_sprite(game, _exit_opened, x, y);
	else
		render_sprite(game, _emptyspace, x, y);
}