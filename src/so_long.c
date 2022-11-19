/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:36:54 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 14:43:51 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	// Establish a connection to the correct graphical system
	// and return a void * which holds the location of our current MLX instance
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Video Game");
	mlx_loop(mlx);
	
	return (0);
}
