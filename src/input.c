/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 18:14:49 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle player input
*/

#include "../so_long.h"

int	is_walkable(char ch)
{
	if (ch == '0' || ch == 'C' || ch == 'E' || ch == 'P' || ch == 'N')
		return (1);
	return (0);	
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (keysym == LEFT || keysym == RIGHT || keysym == UP || keysym == DOWN)
	{
		if (keysym == LEFT)
		{
			if (is_walkable(game->map[game->y_shift][game->x_shift - VELOCITY]))
			{
				game->x_shift -= VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == RIGHT)
		{
			if (is_walkable(game->map[game->y_shift][game->x_shift + VELOCITY]))
			{
				game->x_shift += VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == DOWN)
		{
			if (is_walkable(game->map[game->y_shift + VELOCITY][game->x_shift]))
			{
				game->y_shift += VELOCITY;
				game->movements += 1;
			}
		}
		if (keysym == UP)
		{
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
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
		
	//ft_printf("%d => '%c'\n", keysym, keysym);
	ft_printf("Moves: %d\n", game->movements);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)data;
	return (0);
}