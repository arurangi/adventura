/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/21 15:31:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

// Gobal informations
typedef struct s_game {
	void	*mlx;
	void	*window;
}	t_game;
// Map related informations
typedef struct s_map {
	void	*floor;
	void	*extwall;
	void	*intwall;
} t_map;
// Player related informations
typedef struct s_player {
	void	*img;
	int		height;
	int		width;
}	t_player;

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

void	draw_map(t_game game)
{
	t_map	map;
	int		height;
	int		width;

	map.floor = mlx_xpm_file_to_image(game.mlx, "./assets/xpm/floor_1.xpm", &width, &height);
	height = 0;
	while (height < 520)
	{
		width = 0;
		while (width < 520)
		{
			mlx_put_image_to_window(game.mlx, game.window, map.floor, width, height);
			width += 40;
		}
		height += 40;
	}
}

int	main(void)
{
	t_game		game;
	//t_map		map;
	//t_player	player;
	
	// Initialize the library	
	game.mlx = mlx_init();
	if (game.mlx)
	{
		game.window = mlx_new_window(game.mlx, 520, 520, "Video Game");
		draw_map(game);
		mlx_loop(game.mlx);
	}
	return (0);
}
