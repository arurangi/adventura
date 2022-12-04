/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:07 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/04 13:53:53 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Handle player input
*/

#include "../so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (keysym == LEFT)
		game->x_shift -= 1;
	if (keysym == RIGHT)
		game->x_shift += 1;
	if (keysym == DOWN)
		game->y_shift += 1;
	if (keysym == UP)
		game->y_shift -= 1;
		
	ft_printf("%d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)data;
	return (0);
}