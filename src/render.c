/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/01 15:14:27 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
  int x;
  int y;
  
  x = 0;
  y = 0;
	if (game->window == NULL)
        return (1);
    
    /* BUILD IMAGE */
    //render_background(&game->empty_space, encode_rgb(255, 255, 200));
    /* Background */
    render_rect(&game->img, (t_shape){0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
    /* Green squere */
    render_rect(&game->img, (t_shape){ game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});
    /* Red square */
    //render_rect(&game->img, (t_shape){x, y, 500, 300, encode_rgb(255, 0, 0)});

    /* PUSH IMAGE TO WINDOW */
    mlx_put_image_to_window(game->mlx, game->window, game->img.mlx_img, 0, 0);
	
    return (0);
}