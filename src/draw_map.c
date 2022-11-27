/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:17 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/27 11:41:04 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_game *game)
{
	if (!game)
	{
		write(1, "Error: no <game> struct found.\n", 31);
		return ;
	}
	map_is_valid(game);
		//ft_printf("The map %s is \033[32mvalid\033[0m!\n\n", game->map_filepath + 12);
		//load_assets(game);
		
		//ft_printf("Map %s is\033[31m not valid\033[0m!\n\n", game->map_filepath + 12);
}
