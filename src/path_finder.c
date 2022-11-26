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

typedef struct s_graph {
	char			ch;
	char			position[2];
	struct graph	*next;
	struct graph	*previous;
	int				visited;
} t_graph;

int	path_finder(t_game *game)
{
	// Create new queue
	t_graph	queue;
	// Add all of neighbour to search queue
	queue = enque(queue);
	// While the queue isn't empty
	while (q_not_empty(queue))
	{
		// Grab first person off the queue
		current = pop_head_queue();
		// Check whether the person is a mango seller
		if (not_visited())
		{
			if (found_exit(queue.ch))
			{
				// You're done!
				return (1);
			}
			else
			{
				// Add all of this person's friends to the queue
				// Mark that person as searched/visited
			}
		}
	}
	// If you reached here, no one was a mango seller
	return (0);
}

// Keep a queus
// get_head()
// get_tail()
// enqueue();
// dequeue();
// q_is_empty();

int	found_exit(char ch)
{
	if (ch == 'E')
		return (1);
	return (0);
}

void	