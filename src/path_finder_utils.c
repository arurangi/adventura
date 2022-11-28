/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:13:21 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/28 12:21:28 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Check if node has neem visited, based on coordinates
int	visited(t_node *queue, int head)
{
	int		i;
	t_node	current;

	current = queue[head];
	i = 0;
	while (i < head)
	{
		if (queue[i].row == current.row && queue[i].col == current.col)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// Add node to a matrix of nodes
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
	t_node	current;
	int		pos;
	int		row;
	int		col;

	current = add_node(queue[head].row, queue[head].col);
	//ft_printf("Current at [%d][%d]\n", current.row, current.col);
	pos = head + 1;
	row = current.row - 1;
	while (row <= current.row + 1)
	{
		col = current.col - 1;
		while (col <= current.col + 1)
		{
			// Avoid walls
			if (game->map[row][col] == '1')
				col++;
			// Avoid center
			else if ((row == current.row) && (col == current.col))
				col++;
			// Add node
			else
			{
				queue[pos++] = add_node(row, col);
				*tail += 1;
				col++;
			}
		}
		row++;
	}
	for (int i = head + 1; i <= *tail; i++)
		ft_printf("'%c' (%d, %d)\n", game->map[queue[i].row][queue[i].col], queue[i].row, queue[i].col);
	ft_printf("head: %d, tail: %d\n", head, *tail);
}
