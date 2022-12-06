/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:08:53 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/06 15:06:46 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Quit the game in a clean way, without errors or memory leaks
*/

#include "../so_long.h"

int	game_over(t_game *game)
{
	if (game->map == NULL)
		free_matrix(game->map);	
	free_assets(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	i;
	
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

