/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 17:33:28 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;

	void	*img_data;
	// Initialize the library	
	mlx = mlx_init();
	if (mlx)
	{
		// Set & open the window
		window = mlx_new_window(mlx, 1920, 1080, "Video Game");
		// Collect image data 
		img_data = mlx_xpm_file_to_image(mlx, "square-monster.xpm", &width, &height);
		// Print image to window
		mlx_put_image_to_window(mlx, window, img_data, 0, 0);

		// Repeat the process
		mlx_loop(mlx);
	}
	
	return (0);
}
