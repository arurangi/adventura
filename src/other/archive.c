/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:55:36 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 13:57:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Handle key pressed
/*
int	key_pressed(int key, void *param)
{	
	(void)param;
	if (key == 126 || key == 13)
		ft_printf("Up ");
	else if (key == 125 || key == 1)
		ft_printf("Down ");
	if (key == 123 || key == 0)
		ft_printf("Left ");
	else if (key == 124 || key == 2)
		ft_printf("Right ");
	else
		ft_printf("[%d] ", key);
	return (0);
}

int	key_hook(int keycode, t_game game)
{
	(void)keycode;
	(void)game;
	ft_printf("Hello from key_hook\n");
	return (0);
}
*/

// Map is valid
/*
if (map_is_valid())
	map_init(game);
	height = 0;
	while (height < 520)
	{
		width = 0;
		while (width < 520)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->empty_space, width, height);
			width += 40;
		}
		height += 40;
	}
}
*/

// Initialize the map
/*
static void	map_init(t_game game, t_map map)
{
	map.empty_space = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.wall = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.collectible = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
	map.exit = mlx_xpm_file_to_image(game.mlx, "./assets/sprites/floor_1.xpm", &width, &height);
}
*/

// Find Width, longest line. 
/*
// Find width
int	find_width(int fd)
{
	char	buffer[1];
	int		count;

	count = 0;	
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == 'I')
			count++;
	}
	// 
	return (count);
}
*/