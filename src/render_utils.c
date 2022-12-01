/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:30:28 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/01 19:42:36 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render_emptyspace(t_game *game)
{
	t_asset	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx, "../assets/sprites/floor_1.xpm", &img.width, &img.height);
	if (img.ptr == NULL)
		return (1);
	return (0);
}

int render_rect(t_img *img, t_shape rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;

//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(int *)pixel = color;
//     ft_printf("\033[32m✓\033[0m Inside img_pix_put()\n");
// }

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
