/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/29 21:29:59 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * so_long()
 *
 * Creating a 2D game
 * 
*/

#define ESC 65307
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#include "../so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_printf("%d\n", keysym);
	return (0);
}

int	handle_no_event(void *game)
{
	(void)game;
	// This function needs to exist, but it is useless for the moment
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	
	// Initialize the environment
	if (argc != 2 || invalid_extension(argv[1]))
	{
		write(1, "Usage: ./so_long <map-path>.ber\n", 32);
		return (1);
	}
	game.map_filepath = argv[1];
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_printf("Lib error: can't initialize minilibx");
		return (1);
	}
	// Launch game
	if (map_is_valid(&game))
	{
		game.window = mlx_new_window(game.mlx, W_WIDTH, W_HEIGHT, "Adventura");
		if (game.window == NULL)
		{
			free(game.window);
			return (1);
		}
		
		mlx_loop_hook(game.mlx, &handle_no_event, &game);
		mlx_hook(game.window, 2, 1L<<0, &handle_input, &game);
		
		mlx_loop(game.mlx);
	}
	// End Game
	//mlx_destroy_window(game.mlx, game.window);
	//mlx_destroy_display(game.mlx);
	free(game.mlx);
	
	return (0);
}
