/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:41 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/23 12:10:30 by arurangi         ###   ########.fr       */
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

	map_init(game);
	// I can open the file
	fd = open(game->mpath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File Error: invalid file descriptor");
		return (0);
	}
	// Allocate memory table
	game->map_height = find_height(fd);
	game->map = malloc(sizeof(char *) * ( game->map_height + 1));
	if (!game->map)
		return (0);
	// Save each map line into struct
	fd = open(game->mpath, O_RDONLY);
	row = 0;
	while (row < game->map_height)
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
			// Valid characters (0, 1, C, E, P)
			if (not_valid_character(game->map[row][col]))
			{
				ft_printf("Not valid character at [%d][%d]\n", row, col);
				return (0);
			}
			// Surrounded by walls
			if (row == 0 || row == game->map_height - 1 || col == 0
				|| game->map[row][col + 1] == '\0'
				|| game->map[row][col + 1] == '\n') 
			{
				if (game->map[row][col] != '1')
				{
					ft_printf("Not surrounded by walls at [%d][%d]\n", row, col);
					return (0);
				}
			}
			// At least one : C, E, P
			if (game->map[row][col] == 'C')
				game->c_credit++;
			if (game->map[row][col] == 'E')
				game->e_credit++;
			if (game->map[row][col] == 'P')
				game->p_credit++;
			col++;
		}
		row++;
	}
	// Check credits
	if (game->c_credit == 0)
		ft_printf("Your map needs a COLLECTIBLE\n");
	if (game->e_credit == 0)
		ft_printf("Your map needs an EXIT\n");
	if (game->p_credit == 0)
		ft_printf("Your map needs a PLAYER position\n");
	return (1);
}


// At least one C, E and P
// Must be valid path


int	not_valid_character(char ch)
{
	if (ch == '0'
		|| ch == '1'
		|| ch == 'C'
		|| ch == 'E'
		|| ch == 'P')
		return (0);
	return (1);
}

void	map_init(t_game *game)
{
	game->c_credit = 0;
	game->e_credit = 0;
	game->p_credit = 0;
}


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

