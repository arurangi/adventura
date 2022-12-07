/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:41 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:11:13 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Verify whether the map check all necessary conditions
 *
 * - valid characters (0, 1, C, E, P)
 * - surrounded by walls
 * - at least one : C, E, P
 * - map is rectangular
 * - no duplicates of E or P
 * - valid path
*/

#include "../../so_long.h"

int	map_checker(t_game *game)
{
	int		row;
	int		col;

	// Parsing: save each map line into a table for easy access
	game->map = ft_split_fd(game->map_filepath, '\n');
	if (game->map == NULL)
		return (error_msg(0, "couldn't store the map in the matrix"));

	// Analyze the map further
	game->map_height = tab_height(game->map);
	game->map_width = ft_strlen(game->map[0]);
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while(game->map[row][col])
		{
			// Valid characters (0, 1, C, E, P)
			if (!valid_character(game->map[row][col]))
				return (error_msg(0, "invalid character at [%d][%d]", row, col));
			// Surrounded by walls
			if (row == 0 || row == game->map_height - 1 || col == 0	|| game->map[row][col + 1] == '\0') 
			{
				if (game->map[row][col] != '1')
					return (error_msg(0, "Not surrounded by walls at [%d][%d]\n", row, col));
			}
			// At least one : C, E, P
			if (game->map[row][col] == 'C')
				game->c_credit++;
			if (game->map[row][col] == 'E')
				game->e_credit++;
			if (game->map[row][col] == 'P')
			{
				game->p_credit++;
				game->starting_pos.row = row;
				game->starting_pos.col = col;
			}
			// Map is rectangular
			if ((game->map[row][col + 1] == '\0') && (col + 1 != game->map_width))
					return (error_msg(0, "not rectangular at row %d", row));
			col++;
		}
		row++;
	}
	
	// Check credits
	if ((game->c_credit * game->e_credit * game->p_credit) == 0)
		return (error_msg(0, "missing Collectible (C), Exit (E) or Starting position (P)."));
	// Check for duplicates
	if (game->e_credit > 1 || game->p_credit > 1)
		return (error_msg(0, "duplicates of Exit/Start"));
	// Check for valid path
	if (path_finder(game) == 1)
		return (1);
	return (error_msg(0, "invalid map"));
}
