/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:17 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/21 17:37:20 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	draw_map(t_game game)
{
	t_map	map;
	int		height;
	int		width;

	if (valid_map(map.path))
	{
		map_init(game, map);
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
	else
		ft_printf("Error: invalid map");
}

static int	valid_map(char *path)
{
	// path is not empty
	// path name end with .ber
	// files opens
	// 
}

static void	map_init(t_game game, t_map map)
{
	map.empty_space = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.wall = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.collectible = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.exit = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
}