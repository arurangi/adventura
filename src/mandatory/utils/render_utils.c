/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:15:51 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/08 11:19:06 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	render_player(t_game *game, int x, int y)
{
	void	*img_ptr;

	img_ptr = game->sprites[5].img;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, x * TILE, y * TILE + HUD);
}

void	render_sprite(t_game *game, int asset, int x, int y)
{
	void	*img_ptr;

	if (asset == _emptyspace)
		img_ptr = game->sprites[0].img;
	else if (asset == _wall)
		img_ptr = game->sprites[1].img;
	else if (asset == _collectible)
		img_ptr = game->sprites[2].img;
	else if (asset == _exit_closed)
	{
		if (game->c_credit == 0)
			img_ptr = game->sprites[4].img;
		else
			img_ptr = game->sprites[3].img;
	}
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, x * TILE, y * TILE + HUD);
}

void	render_hud(t_game *game)
{
	mlx_string_put(game->mlx, game->window,
		15, 12, rgbify(255, 255, 255), "Steps count: ");
	mlx_string_put(game->mlx, game->window,
		150, 12, rgbify(255, 255, 255), ft_itoa(game->movements));
}

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
