/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:41 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/23 10:24:22 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Check if the map is "valid":
 *
 * valid .ber file
 * file exists
 * 
 * 
*/

#include "../libft.h"

int	find_height(int fd);

int	map_is_valid(t_game *game)
{
	int		fd;
	int		row;
	int		col;

	// -> Open file
	fd = open(game->mpath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File Error: invalid file descriptor");
		return (0);
	}
	// Allocate memory table
	game->m_height = find_height(fd);
	game->map = malloc(sizeof(char *) * ( game->m_height + 1));
	if (!game->map)
		return (0);
	// Save each map line into struct
	fd = open(game->mpath, O_RDONLY);
	row = 0;
	while (row < game->m_height)
	{
		game->map[row] = get_next_line(fd);
		row++;
	}
	game->map[row] = NULL;
	
	// Check game.map for valid content, line by line
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while(game->map[row][col] && game->map[row][col] != '\n')
		{
			// Check walls
			if (row == 0 || row == game->m_height - 1 || col == 0 || game->map[row][col + 1] == '\0') 
			{
				if (game->map[row][col] != '1' && game->map[row][col] != '\0')
				{
					ft_printf("Error: map not surrounded by walls @[%d][%d]\n", row, col);
					return (0);
				}
			}
			col++;
		}
		row++;
	}
	return (1);
}

// Valid characters (0, 1, C, E, P)
// At least one C, E and P
// Must be valid path

/*
int	valid_character(char ch)
{
	if (ch == '0'
		|| ch == '1'
		|| ch == 'C'
		|| ch == 'E'
		|| ch == 'P')
		return (1);
	return (0);
}
*/

// Find height
int	find_height(int fd)
{
	char	*str;
	int		height;

	height = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		height++;
		free(str);
	}
	close(fd);
	return (height);
}

