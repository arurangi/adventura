/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 14:10:02 by Arsene           ###   ########.fr       */
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
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (keysym == LEFT)
	{
		if (is_walkable(game->map[game->y_shift][game->x_shift - 1]))
			game->x_shift -= 1;
	}
	if (keysym == RIGHT)
	{
		if (is_walkable(game->map[game->y_shift][game->x_shift + 1]))
			game->x_shift += 1;
	}
	if (keysym == DOWN)
	{
		if (is_walkable(game->map[game->y_shift + 1][game->x_shift]))
			game->y_shift += 1;
	}
	if (keysym == UP)
	{
		if (is_walkable(game->map[game->y_shift - 1][game->x_shift]))
			game->y_shift -= 1;
	}
		
	ft_printf("%d => '%c'\n", keysym, keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)data;
	return (0);
}