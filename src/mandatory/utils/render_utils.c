/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:15:51 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 11:58:59 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	render_player(t_game *game, int x, int y)
{
	void	*img_ptr;
	
	img_ptr = game->sprites[game->angle].img;
	mlx_put_image_to_window(game->mlx, game->window, img_ptr, x * TILE, y * TILE + HUD);
}

void	render_sprite(t_game *game, char asset, int x, int y)
{
	void	*img_ptr;
	
	if (asset == __emptyspace)
		img_ptr = game->sprites[0].img;
	else if (asset == __wall)
		img_ptr = game->sprites[1].img;
	else if (asset == __collectible)
		img_ptr = game->sprites[4].img;
	else if (asset == __exit)
	{
		if (game->c_credit == 0)
			img_ptr = game->sprites[5].img;
		else
			img_ptr = game->sprites[6].img;
	}
	else if (asset == __enemy)
		img_ptr = game->sprites[11].img;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window,
		img_ptr, x * TILE, y * TILE + HUD);
}

void	render_HUD(t_game *game)
{
	mlx_string_put(game->mlx, game->window,
		15, 12, rgbify(255, 255, 255), "Steps count: ");
	mlx_string_put(game->mlx, game->window,
		150, 12, rgbify(255, 255, 255), ft_itoa(game->movements));
	// mlx_string_put(game->mlx, game->window,
	// 	300, 12, rgbify(255, 255, 255), "Remaining items: ");
	// mlx_string_put(game->mlx, game->window,
	// 	500, 12, rgbify(255, 255, 255), ft_itoa(game->c_credit));
}

int	rgbify(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
