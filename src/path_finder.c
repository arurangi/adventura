/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:08:25 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/25 13:08:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * finds path to exit using 'breath-first search algorithm'
 * an 'adjacency matrix' to represent the graph
 * and a queue as data structure
*/

#include "../so_long.h"

int	path_finder(t_game *game)
{
	int			q_size;
	int			head;
	int			tail;
	t_node		current;

	// Create new queue
	q_size = (game->map_height * game->map_width) + 1;
	t_node	queue[q_size];
	q_init(queue, q_size);

	// Add starting position
	head = 0;
	queue[head] = game->starting_pos;

	// Add all neighbours
	tail = 0;
	add_neighbours(game, queue, head, &tail);

	// Check every node while queue is not empty
	while (queue[head].row != -1)
	{
		current = queue[head];
		if (found_exit(game, current))
			return (1);
		add_neighbours(game, queue, head, &tail);
		head += 1;
	}
	return (map_error(game, "no EXIT found"));
}
