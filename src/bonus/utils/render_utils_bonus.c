/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:15:51 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:04 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

// void	render_player(t_game *game, int x, int y)
// {
// 	void	*img_ptr;

// 	img_ptr = game->sprites[game->angle].img;
// 	mlx_put_image_to_window(game->mlx, game->window,
// 		img_ptr, x * TILE, y * TILE + HUD);
// }

void	render_sprite(t_game *game, int asset, int x, int y)
{
	void	*img_ptr;

	img_ptr = game->sprites[asset].img;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, x * TILE, y * TILE + HUD);
}

void	render_hud(t_game *game)
{
	mlx_string_put(game->mlx, game->window,
		15, 12, rgbify(255, 255, 255), "Steps count: ");
	mlx_string_put(game->mlx, game->window,
		150, 12, rgbify(255, 255, 255), ft_itoa(game->movements));
	mlx_string_put(game->mlx, game->window,
		300, 12, rgbify(255, 255, 255), "Remaining items: ");
	mlx_string_put(game->mlx, game->window,
		500, 12, rgbify(255, 255, 255), ft_itoa(game->c_credit));
}

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
