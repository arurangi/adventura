/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/26 15:30:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * List of short but usefull functions
*/

#include "../so_long.h"

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

// Initialize credits and width
// Check for C, E, P and check if rectangular
void	map_init(t_game *game)
{
	game->c_credit = 0;
	game->e_credit = 0;
	game->p_credit = 0;
	game->map_width = -1;
}


// Find height -> malloc
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