/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 16:32:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		height;
	int		width;

	void	*img_data;
	
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Video Game");
	
	img_data = mlx_xpm_file_to_image(mlx_ptr, "square-monster.xpm", &width, &height);
	width = 1;
	height = 1;
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_data, 0, 0);
	mlx_loop(mlx_ptr);
	
	return (0);
}
