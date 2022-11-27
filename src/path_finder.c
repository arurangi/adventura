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
	static int	head;
	int	tail;
	t_node		current;

	// Create new queue
	q_size = game->map_height * game->map_width;
	t_node	queue[q_size];
	head = 0;
	tail = 0;
	// Add initial position
	queue[head] = game->starting_pos;
	
	// While the queue isn't empty
	while (head < 1)
	{
		// Grab first person off the queue
		current = queue[head];
		// Check whether node is an exit
		if (not_visited(queue, head))
		{
			if (found_exit(game, current))
			{
				// You're done!
				ft_printf("Found an exit\n");
				return (1);
			}
			else
			{
				// Add all of this person's friends to the queue
				add_neighbours(game, queue, head, &tail);
				// Mark that person as searched/visited
			}
		}
		head++;
	}
	// If you reached here, no one was a mango seller
	printf("Head = %d, Tail = %d\n", head, tail);
	int i;

	i = head;
	while (i < tail)
	{
		ft_printf("Queue: [%d][%d] => '%c'\n", queue[i].row, queue[i].col, game->map[queue[i].row][queue[i].col]);
		i++;
	}
	ft_printf("Queue: [%d][%d] => '%c'\n", queue[i].row, queue[i].col, game->map[queue[i].row][queue[i].col]);
	return (1);
}
