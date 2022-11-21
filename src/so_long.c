/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/21 17:32:54 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>



// int	key_pressed(int key, void *param)
// {	
// 	(void)param;
// 	if (key == 126 || key == 13)
// 		ft_printf("Up ");
// 	else if (key == 125 || key == 1)
// 		ft_printf("Down ");
// 	if (key == 123 || key == 0)
// 		ft_printf("Left ");
// 	else if (key == 124 || key == 2)
// 		ft_printf("Right ");
// 	else
// 		ft_printf("[%d] ", key);
// 	return (0);
// }


void	draw_map(t_game game);
int		key_hook(int keycode, t_game game);

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	(void)		argc;
	
	// Valid argument for path
	if (argc != 2)
	{
		ft_printf("Error: Two argument are needed: ./so_long <map-path>\n");
		return (1);
	}
	map.path = argv[1];
	game.mlx = mlx_init();
	if (game.mlx)
	{
		game.window = mlx_new_window(game.mlx, 520, 520, "Video Game");
		draw_map(game, map);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}






int	key_hook(int keycode, t_game game)
{
	(void)keycode;
	(void)game;
	ft_printf("Hello from key_hook\n");
	return (0);
}