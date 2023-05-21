/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:08:53 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/21 16:20:22 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Quit the game in a clean way, without errors or memory leaks
*/

#include "../so_long.h"

int	end_game(t_game *game)
{
	if (game->map != NULL)
		free_matrix(game->map);
	if (game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
