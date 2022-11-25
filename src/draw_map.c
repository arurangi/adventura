/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:17 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/25 15:24:01 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	draw_map(t_game *game)
{
	if (!game)
	{
		write(1, "Error: no <game> struct found.\n", 31);
		return ;
	}
	if (map_is_valid(game))
	{
		ft_printf("\nHourra! The map is valid!\n");
		//load_assets(game);
	}
	else
		ft_printf("\nMap is not valid!\n");
}
