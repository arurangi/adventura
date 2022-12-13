/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/13 20:16:34 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * List of short but usefull functions
*/

#include "../../so_long.h"

int	invalid_extension(char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if ((len > 4)
		&& (filepath[len - 1] == 'r'
			&& filepath[len - 2] == 'e'
			&& filepath[len - 3] == 'b'
			&& filepath[len - 4] == '.'))
		return (0);
	return (1);
}

int	valid_character(char ch)
{
	if (ch == '0'
		|| ch == '1'
		|| ch == 'C'
		|| ch == 'E'
		|| ch == 'P'
		|| ch == 'N'
		|| ch == 'T')
		return (1);
	return (0);
}

int	tab_height(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int	inner_loop_checker(t_game *game, int row, int col)
{
	if (!valid_character(game->map[row][col]))
		return (error_msg(0, "invalid character [%d][%d]", row, col));
	if (row == 0 || row == game->map_height - 1 || col == 0
		|| game->map[row][col + 1] == '\0')
	{
		if (game->map[row][col] != '1')
			return (error_msg(0, "Not surrounded by walls [%d][%d]\n",
					row, col));
	}
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
	if ((game->map[row][col + 1] == '\0')
		&& (col + 1 != game->map_width))
		return (error_msg(0, "not rectangular at row %d", row));
	return (1);
}

int	outer_loop_checker(t_game *game)
{
	if ((game->c_credit * game->e_credit * game->p_credit) == 0)
		return (error_msg(0, "missing (C), (E) or (P)"));
	if (game->e_credit > 1 || game->p_credit > 1)
		return (error_msg(0, "duplicates of Exit/Start"));
	return (1);
}
