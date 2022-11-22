/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 11:54:20 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc != 2)
	{
		ft_printf("Error: Two argument are needed: %s <map-path>.ber\n", argv[0]);
		return (1);
	}
	game.mpath = argv[1];
	game.mlx = mlx_init();
	if (game.mlx)
	{
		game.window = mlx_new_window(game.mlx, 1920, 1080, "Video Game");
		draw_map(&game);
		mlx_loop(game.mlx);
	}
	return (0);
}

