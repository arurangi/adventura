/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/05 16:06:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle user input {W, S, A, D} to have ability to
 * move in all directions within the walls
*/

#include "../so_long.h"





int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		destroy_sprites_images(game);
		mlx_destroy_image(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		free(game->mlx);
	}
	if (keysym == LEFT || keysym == RIGHT || keysym == UP || keysym == DOWN)
	{
		if (keysym == LEFT)
		{
			game->angle = 9;
			if (is_walkable(game->map[game->y_shift][game->x_shift - VELOCITY]))
			{
				game->x_shift -= VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == RIGHT)
		{
			game->angle = 10;
			if (is_walkable(game->map[game->y_shift][game->x_shift + VELOCITY]))
			{
				game->x_shift += VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == DOWN)
		{
			game->angle = 7;
			if (is_walkable(game->map[game->y_shift + VELOCITY][game->x_shift]))
			{
				game->y_shift += VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == UP)
		{
			game->angle = 8;
			if (is_walkable(game->map[game->y_shift - VELOCITY][game->x_shift]))
			{
				game->y_shift -= VELOCITY;
				game->movements += 1;
			}
		}
	}
	// Handle collectibles
	if (game->map[game->y_shift][game->x_shift] == 'C')
	{
		game->map[game->y_shift][game->x_shift] = '0';
		game->c_credit -= 1;
	}
	// Handle exit
	if (game->map[game->y_shift][game->x_shift] == 'E' && game->c_credit == 0)
	{
		game->map[game->y_shift][game->x_shift] = '0';
		mlx_destroy_window(game->mlx, game->window);
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
		
	ft_printf("Moves: %d\n", game->movements);
	ft_printf("Key: %d\n", keysym);
	return (0);
}
