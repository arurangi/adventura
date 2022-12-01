/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/01 11:23:52 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (game->window == NULL)
        return (1);
    
    render_background(&game->empty_space, encode_rgb(255, 255, 255));
    
    render_rect(&game->img, (t_rect){W_WIDTH - 100, W_HEIGHT - 100,
		100, 100, encode_rgb(85, 208, 81)});
    render_rect(&game->img, (t_rect){0, 0, 500, 300, encode_rgb(255, 0, 0)});

    mlx_put_image_to_window(game->mlx, game->window, game->img.mlx_img, 0, 0);
	
    return (0);
}