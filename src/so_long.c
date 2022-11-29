/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/29 15:02:31 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * so_long()
 *
 * Creating a 2D game
 * 
*/

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc != 2 || invalid_extension(argv[1]))
	{
		write(1, "Usage: ./so_long <map-path>.ber\n", 32);
		return (1);
	}
	game.map_filepath = argv[1];
	game.mlx = mlx_init();
	if (game.mlx)
	{
		draw_map(&game);
	}
	
	return (0);
}
