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
 * path_finder()
 *
 * finds a path to the exit, if any
 * based on a map, a starting position and the position of a 
 * depending on walls
 * 
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

	// While the queue isn't empty
	// head <= tail && tail < q_size && 
	while (queue[head].row != -1)
	{
		// Grab first person off the queue
		current = queue[head];
		// Check whether node is an exit
		if (found_exit(game, current))
		{
			// You're done!
			return (1);
		}
		else
			// Add all of this person's friends to the queue
			add_neighbours(game, queue, head, &tail);
		head += 1;
	}
	// If you reached here, no one was a mango seller
	return (map_error("no EXIT found"));
}
