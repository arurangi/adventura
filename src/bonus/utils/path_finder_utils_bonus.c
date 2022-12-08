/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:13:21 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/08 21:37:05 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

// Check if node has neem visited, based on coordinates
int	in_queue(t_node current, t_node *queue, int head, int tail)
{
	int		i;

	i = 0;
	while (i <= tail)
	{
		if (i == head)
			i++;
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

// Initialize the queue
void	q_init(t_node *queue, int q_size)
{
	int	i;

	i = 0;
	while (i < q_size)
	{
		queue[i] = add_node(-1, -1);
		i++;
	}
}

// Check if an exit was found
int	found_exit(t_game *game, t_node node)
{
	if (game->map[node.row][node.col] == 'E')
		return (1);
	return (0);
}

int	valid_position(t_game *game, int row, int col, t_node current)
{
	if (game->map[row][col] == '1' || game->map[row][col] == 'P'
		|| game->map[row][col] == 'N')
		return (0);
	if ((row == current.row) && (col == current.col))
		return (0);
	return (1);
}
