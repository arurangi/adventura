/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:41 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/22 11:51:40 by arurangi         ###   ########.fr       */
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

int	map_is_valid(t_game *game)
{
	int		fd;
	
	if (valid_ber_file(game.mpath))
	{
		// Open file
		fd = open(game.mpath, O_RDONLY);
		if (!fd)
			ft_printf("Invalid file");
		// Calculate size of the map
		// Allocate a memory for the map
		game.map = malloc(sizeof(char *) * (line_count() + 1));
	}
	
	// files opens
	// 
	return (1)
}

static int	valid_ber_file(char *filepath)
{
	int		len;
	char	*ext;

	len = ft_strlen(filepath);
	if ((len > 4) 
		&& (filepath[len - 1] == 'r'
		&& filepath[len - 2] == 'e'
		&& filepath[len - 3] == 'b'
		&& filepath[len - 4] == '.'))
		return (1);
	return (0);
}