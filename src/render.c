/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/30 16:24:08 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (game->window == NULL)
        return (1);
        
    ft_printf("\033[33mRendering...\033[0m\n");
    
    render_background(&game->empty_space, encode_rgb(255, 255, 255));
    ft_printf("\033[32m✓\033[0m Background rendered\n");
    
    render_rect(&game->img, (t_rect){W_WIDTH - 100, W_HEIGHT - 100,
		100, 100, encode_rgb(85, 208, 81)});
    render_rect(&game->img, (t_rect){0, 0, 500, 300, encode_rgb(255, 0, 0)});

    mlx_put_image_to_window(game->mlx, game->window, game->img.mlx_img, 0, 0);
	
    return (0);
}