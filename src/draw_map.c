/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:17 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 16:12:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	draw_map(t_game *game)
{
	if (map_is_valid(game))
		ft_printf("Hourra! The map is valid!\n");
}
