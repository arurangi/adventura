/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/03 20:03:49 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int	render(t_game *game)
{
	if (game->window == NULL)
        return (1);
        
  render_rect(&game->image, (t_shape)
      {0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
  render_rect(&game->image, (t_shape)
      { game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});

    return (0);
}

// render_rect(&game->image, (t_shape)
//       {0, 0, W_WIDTH, W_HEIGHT, encode_rgb(255, 255, 255)});
// render_rect(&game->image, (t_shape)
//       { game->x_shift, game->y_shift, 100, 100, encode_rgb(85, 208, 81)});