/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:06:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:49:57 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_arrow_keys(int keysym)
{
	if (keysym == LEFT_KEY || keysym == RIGHT_KEY
		|| keysym == UP_KEY || keysym == DOWN_KEY)
		return (TRUE);
	return (FALSE);
	
}

int	is_walkable(t_game *game, char ch)
{
	if (ch == '0' || ch == 'C' || ch == 'P' || ch == 'T' || (ch == 'E' && game->c_credit == 0))
	{
		game->steps_count += 1;
		ft_printf("steps: %d\n", game->steps_count);
		return (1);
	}
	if (ch == 'N')
		game->life_points -= 1;
	return (0);
}

int	is_walkable_enemy(char ch)
{
	if (ch == '0' || ch == 'P' || ch == 'E' || ch == 'N')
		return (1);
	return (0);
}


