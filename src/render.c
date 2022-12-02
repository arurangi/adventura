/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/02 12:31:02 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (game->window == NULL)
        return (1);

    /* BUILD IMAGE */
    render_rect(&game->image, (t_shape)
      {0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
    render_rect(&game->image, (t_shape)
      { game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});

    // int width;
    // int height;
   
    //mlx_xpm_file_to_image(game->mlx, "../assets/sprites/floor_1.xpm", &width, &height);

    /* PUSH IMAGE TO WINDOW */
    mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);
	
    return (0);
}