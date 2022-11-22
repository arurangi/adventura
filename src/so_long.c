/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 16:57:20 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	invalid_extension(char *filepath);

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc != 2 || invalid_extension(argv[1]))
	{
		ft_printf("Usage: %s <map-path>.ber\n", argv[0]);
		return (1);
	}
	game.mpath = argv[1];
	game.mlx = mlx_init();
	if (game.mlx)
	{
		//game.window = mlx_new_window(game.mlx, 1920, 1080, "Video Game");
		draw_map(&game);
		//mlx_loop(game.mlx);
	}
	// while (1)
	// {
		
	// }
	//system("leaks ./runthis");
	return (0);
}

static int	invalid_extension(char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if ((len > 4) 
		&& (filepath[len - 1] == 'r'
		&& filepath[len - 2] == 'e'
		&& filepath[len - 3] == 'b'
		&& filepath[len - 4] == '.'))
		return (0);
	return (1);
}

