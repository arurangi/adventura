/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/02 10:01:24 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_game_environment(t_game *game, int ac, char **av)
{
	// Valid arguments
	if (ac != 2 || invalid_extension(av[1]))
	{
		write(1, "Usage: ./so_long <map-path>.ber\n", 32);
		return (1);
	}
	game->map_filepath = av[1];
	
	// Launch minilibx library
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_printf("Lib error: can't initialize minilibx");
		return (1);
	}

	// Get window's pointer
	game->window = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (1);
	}
	// Player
	game->x_shift = 0;
  	game->y_shift = 0;
	
	return (0);
}