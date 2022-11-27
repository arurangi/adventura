/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:13:21 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/27 13:20:48 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	not_visited(t_node *queue, int head)
{
	int	i;

	i = 0;
	if (head == 0)
		return (1);
	while (i < head)
	{
		if (queue[i].row == queue[head].row && queue[i].col == queue[head].col)
			return (0);
		i++;
	}
	return (1);
}

t_node	add_node(int row, int col)
{
	t_node	node;

	node.row = row;
	node.col = col;
	return (node);
}

// Check if an exit was found
int	found_exit(t_game *game, t_node node)
{
	if (game->map[node.row][node.col] == 'E')
		return (1);
	return (0);
}

// Add all friends to the queue
void	add_neighbours(t_game *game, t_node *queue, int head, int *tail)
{
	int		row;
	int		col;
	int		pos;
	t_node	current;
	(void)game;

	ft_printf("Position [%d][%d]\n\n", queue[head].row, queue[head].col);

	current = add_node(queue[head].row, queue[head].col);
	pos = head + 1;
	row = current.row - 1;
	while (row <= current.row + 1)
	{
		// Avoid places outside the matrix
		if (row < 0)
			row++;
		if (row > game->map_height - 1)
			break ;

		col = current.col - 1;
		while (col <= current.col + 1)
		{
			
			if (col < 0)
				col++;
			else if (col > game->map_width - 1)
				break ;
			// Avoid walls
			else if (game->map[row][col] == '1')
				col++;
			// Avoid center
			else if ((row == current.row) && (col == current.col))
				col++;
			else
			{
				// Add node
				queue[pos++] = add_node(row, col);
				*tail += 1;
			}
			col++;
		}
		row++;
	}
}
